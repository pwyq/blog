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

## 跟踪文件

- 强制跟踪指定文件：`git update-index --no-assume-unchanged <file>`
- 强制不跟踪指定文件：`git update-index --assume-unchanged <file>`

## Git 标签操作

- 基于 `HEAD` 新建标签：`git tag <name>`
    - 基于指定 commit 新建标签：`git tag <name> <commit>`
    - 指定标签信息：`git tag -m <message> <name>`
    - 使用PGP签名标签：`git tag -s <name>`
- 查看标签：`git tag`
- 推送指定标签到指定远程仓库：`git push <repo-name> <tag-name>`
    - 推送全部标签到指定远程仓库：`git push <repo-name> --tags`
- 在指定远程仓库删除指定标签：`git push <repo-name> :refs/tags/<tag-name>`

## Git 子模块操作

- 添加 submodule：`git submodule add -b <branch> --name <name> <repo> <path>`
- 查看 submodule 状态：`git submodule status`
- clone 含 submodule 的项目
    - 方法一：`git clone <repo> --recursive`
    - 方法二：

        ```
        git clone <repo>
        git submodule update --init --recursive
        ```
- 删除 submodule：

    ```
    git deinit <path>
    git rm --cached <path>
    rm -rf <path>
    [edit .gitmodules to remove submodule item]
    ```
- 在 submodule 中执行命令：`git submodule foreach <command>`
- 更新 submodule：`git submodule update --recursive --remote`

## Fun Facts

1. 在 Git 中，`HEAD` 表示当前版本，也就是最新的提交，上一个版本就是 `HEAD^`，上上一个版本就是 `HEAD^^`，上100个版本写成 `HEAD~100`。
2. 很多命令都有 `-n` 或 `--dry-run` 选项，使用了该选项后，命令不会直接运行，而是输出它将执行的内容，供用户判断执行的内容是否和预期一致，从而决定是否实际执行该命令。这避免了一些手误的情况，在某些重要的操作上很有用。
3. Git 的命令中常含有 `--`，它用来分割 Git 命令的选项和文件/文件列表，以防某些文件名被误认为是选项。

## Reference
1. [Git Official Website](https://git-scm.com/)
2. [Git Cheat Sheet](http://uchuhimo.me/2017/04/18/git-cheat-sheet/)