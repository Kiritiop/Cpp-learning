def playGame(deck):
    cards = deck.split()
    
    RANKS = {'A': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7,
             '8': 8, '9': 9, 'T': 10, 'J': 11, 'Q': 12, 'K': 13}
    reds = {'H', 'D'}
    
    def rank(card):
        return RANKS[card[0]]
    
    def color(card):
        return 'R' if card[1] in reds else 'B'
    
    def canPlace(c, top):
        return color(c) != color(top) and rank(c) == rank(top) - 1
    
    hand1 = [cards[i] for i in range(0, 14, 2)]
    hand2 = [cards[i] for i in range(1, 14, 2)]

    piles = [[], [], [], [], [], [], [], []]
    piles[0] = [cards[14]]
    piles[2] = [cards[15]]
    piles[4] = [cards[16]]
    piles[6] = [cards[17]]
    
    draw = cards[18:]
    
    def move(piles, hand):
        for i in range(8):
            if not piles[i]:
                continue
            bottom_i = piles[i][0]
            for j in range(8):
                if i == j or not piles[j]:
                    continue
                if canPlace(bottom_i, piles[j][-1]):
                    piles[j] = piles[j] + piles[i]
                    piles[i] = []
                    if hand:
                        min_r = min(rank(c) for c in hand)
                        for idx, c in enumerate(hand):
                            if rank(c) == min_r:
                                piles[i] = [hand.pop(idx)]
                                break
                    return True
        return False
    
    def play(piles, hand):
        played = 0
        while True:
            placed = False
            for i, card in enumerate(hand):
                if rank(card) == 13:
                    for j in [1, 3, 5, 7]:
                        if not piles[j]:
                            piles[j] = [card]
                            hand.pop(i)
                            played += 1
                            placed = True
                            break
                else:
                    for j in range(8):
                        if piles[j] and canPlace(card, piles[j][-1]):
                            piles[j].append(card)
                            hand.pop(i)
                            played += 1
                            placed = True
                            break
                if placed:
                    break
            if not placed:
                break
        return played
    
    def out(winner, piles):
        parts = [str(winner)]
        for pile in piles:
            parts.append(pile[-1] if pile else 'E')
        return ' '.join(parts)
    
    player = 1
    
    for i in range(200000):
        hand = hand1 if player == 1 else hand2
        
        pileMove = move(piles, hand)
        
        if not hand:
            return out(player, piles)
        
        cards_played = play(piles, hand)
        
        if not hand:
            return out(player, piles)
        
        if not pileMove and cards_played == 0:
            if draw:
                hand.append(draw.pop(0))
        
        player = 2 if player == 1 else 1
    
    return out(player, piles)