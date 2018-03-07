---
title: Git Cheat Sheet
date: 2018-02-27
categories: 
    - cheatsheet
tags:
    - Git
    - Cheat Sheet
description: Command list for the most popular distributed version control system - Git
---

<style>
table { width: 100% }
table th:nth-child(1) { width: 40%; }
table th:nth-child(2) { width: 60%; }
</style>

## Create Repositories
Start a new repository or obtain one from an existing URL

| command | description |
|:-------:|:-----------:|
| `git init <project-name>` | Initialize a new local repository with the specified name |
| `git clone <url>` | Downloads a project and its entire version history |

## Configure Tooling
Configure user information for all local repositories

| command | description |
|:-------:|:-----------:|
| `git config --global user.name "<name>"` | Sets the name to your commit transactions |
| `git config --global user.email "<email address>"` | Sets the email to your commit transactions |
| `git config --global color.ui auto` | Enables helpful colorization of command line output |
| `git config core.editor "vim"` | Set vim as default text editor (e.g., editing commit message) (nano is too hard for me:))|

## Make Changes
Review edits and craft a commit transaction

| command | description |
|:-------:|:-----------:|
| `git status` | Lists all new or modified files to be committed |
| `git diff` | Shows file differences not yet staged |
| `git add <file>` | Snapshots the file in preparation for versioning |
| `git add -A` _or_ `git add .` | Includes all modification in stage |
| `git diff --staged` | Shows file differences between staging and the last file version |
| `gie reset <file>` | Unstages the file, but preserve its contents |
| `git commit -m "<descriptive message>"` | Records file snapshots permanently in version history |
| `git commit --amend` | Modifies commit message for not pushed commit; if pushed, use `git push --force <branch>` |

## Group Changes
Name a series of commits and combine completed efforts

| command | description |
|:-------:|:-----------:|
| `git branch` | Lists all local branches in the current repository |
| `git branch <branch-name>` | Creates a new branch |
| `git checkout <branch-name>` | Switches to the specified branch and updates the working directory |
| `git merge <branch>` | Combines the specified branch's history into the current branch |
| `git branch -d <branch-name>` | Deletes the specified branch locally |
| `git push origin :<branch-name>` | Deletes the specified branch remotely |

## Refactor Filenames
Relocate and remove versioned files

| command | description |
|:-------:|:-----------:|
| `git rm <file>` | Deletes the file from the working directory and stages the deletion |
| `git rm --cached <file>` | Removes the file from version control but preserves the file locally |
| `git mv <file-original> <file-renamed>` | Changes the file name and prepares it for commit |
| `git clean (-d) <file>` | Removes untracked files from working tree (locally), `-d` for directory | 

## Suppress Tracking
Exclude temporary files and paths

| command | description |
|:-------:|:-----------:|
| `vim .gitignore` | Creates a text file named `.gitignore` to exclude specified files from versioning |
| `git ls-files --other --ignored --exclude-standard` | Lists all ignored files in this project |

## Save Fragments
Shelve and restore incomplete changes

| command | description |
|:-------:|:-----------:|
| `git stash` | Temporarily stores all modified tracked files |
| `git stash pop` | Resotres the most recently stashed files |
| `git stash list` | Lists all stashed changesets |
| `git stash drop` | Discards the most recently stashed changeset |

## Review History
Browse and inspect the evolution of project files

| command | description |
|:-------:|:-----------:|
| `git log (--graph --color)` | Lists version history for the current branch |
| `git reflog` | Reference logs, records when the tips of branches and other references were updated locally. |
| `git log --follow <file>` | Lists version history for a file, including renames |
| `git dff <first-branch>...<second-branch>` | Shows content differences between two branches |
| `git show <commit>` | Outputs metadata and content changes of the specified commit |

## Redo Commits 
Erase mistakes and craft replacement history

| command | description |
|:-------:|:-----------:|
| `git reset <commit>` | Undoes all commits after `<commit>`, preserving changes locally |
| `git reset --hard <commit>` | Discards all history and changes back to the specified commit |
| `git reset --soft <commit>` | Undos a local commit and keeps changes |

## Synchronize Changes
Register a repository bookmark and exchange version history

| command | description |
|:-------:|:-----------:|
| `git fetch <bookmark>` | Downloads all history from the repository bookmark |
| `git merge <bookmark>/<branch>` | Combines bookmark's branch into current local branch |
| `git push <alias> <branch>` | Uploads all local branch commits to Remote |
| `git pull` | Downloads bookmark history and incorporates changes |

## Track Files

- Force tracking target file：`git update-index --no-assume-unchanged <file>`
- Force not tracking target file：`git update-index --assume-unchanged <file>`

## Tag Operation

- Based on `HEAD`：`git tag <name>`
    - Based on specific commit：`git tag <name> <commit>`
    - Add tag info：`git tag -m <message> <name>`
    - Add tag with PGP：`git tag -s <name>`
- Check tags：`git tag`
- Push specific tag to remote repo：`git push <repo-name> <tag-name>`
    - Push all tags to remote repo：`git push <repo-name> --tags`
- Delete specific tag in specific repo：`git push <repo-name> :refs/tags/<tag-name>`

## Module Operation

- Add submodule：`git submodule add -b <branch> --name <name> <repo> <path>`
- Check submodule status：`git submodule status`
- clone project with submodule
    - method I：`git clone <repo> --recursive`
    - method II：

        ```
        git clone <repo>
        git submodule update --init --recursive
        ```
- Delete submodule：

    ```
    git deinit <path>
    git rm --cached <path>
    rm -rf <path>
    [edit .gitmodules to remove submodule item]
    ```
- Execute commands in submodule：`git submodule foreach <command>`
- Update submodule：`git submodule update --recursive --remote`

## Fun Facts

1. In GIt, `HEAD` represent current version (i.e., the latest push); last version is `HEAD^`, last last version is `HEAD^^`, last 100 version is `HEAD~100`.
2. A lot of commands has `-n` or `--dry-run` option. 
When apply such an option, the command won't run; instead, it outputs what it will do, so that user can determine to proceed or not. 

## Reference
1. [Git Official Website](https://git-scm.com/)
2. [Git Cheat Sheet](http://uchuhimo.me/2017/04/18/git-cheat-sheet/)