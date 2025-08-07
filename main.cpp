#include <cstdio>      
#include <algorithm> 

char line[500001];

int main() {
    scanf("%s", line);

    int len = 0;
    int countL = 0;
    int countM = 0;
    for (len = 0; line[len] != '\0'; ++len) {
        if (line[len] == 'L') {
            countL++;
        } else if (line[len] == 'M') {
            countM++;
        }
    }

    int s_misplaced = 0;
    int m_in_l_zone = 0;
    int l_in_m_zone = 0;

    for (int i = 0; i < countL; ++i) {
        if (line[i] != 'L') {
            s_misplaced++;
            if (line[i] == 'M') {
                m_in_l_zone++;
            }
        }
    }

    for (int i = countL; i < countL + countM; ++i) {
        if (line[i] != 'M') {
            s_misplaced++;
            if (line[i] == 'L') {
                l_in_m_zone++;
            }
        }
    }
    
    int result = s_misplaced - std::min(m_in_l_zone, l_in_m_zone);
    printf("%d\n", result);

    return 0;
}