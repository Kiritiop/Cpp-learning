## Reverting a Broken Commit (Git Guide)

During the development of our game, we encountered a problem where all items in the scene hierarchy were purged.  
An easy fix is to revert your changes from a previous commit.

## Find the Broken Commit

```bash
git log --oneline
```

Locate the commit that broke your program.

## Revert the Commit

```bash
git revert <commit-hash>
```

The `<commit-hash>` is a series of numbers and letters. Example:

```bash
git revert 1a2b3c4
```

Then push the changes:

```bash
git push
```

## Handling Merge Conflicts

If you encounter a merge conflict when pushing:

## Check which files have conflicts

```bash
git status
```

## Open the conflicted file

You may see something like:

```text
<<<<<<< HEAD
(current version of the code)
=======
(version from the reverted commit)
>>>>>>> parent of 1a2b3c4 (Commit-Message)
```

- `<<<<<<< HEAD` → Your current version  
- `>>>>>>> parent...` → The version from the commit being reverted  

Choose what you want to keep and delete the rest.

⚠️ **Important:** Remove all conflict markers:

```
<<<<<<<
=======
>>>>>>>
```

Keep only the correct code in the file.

## Mark conflict as resolved

After saving the file:

```bash
git add FileName
```

Example:

```bash
git add Assets/Scripts/GameManager.cs
```

Continue the revert:

```bash
git revert --continue
```

Then push:

```bash
git push
```

## Final Step

Once everyone pulls from `origin`, the repository will reflect the reverted version, and the team can continue development from a stable state.
