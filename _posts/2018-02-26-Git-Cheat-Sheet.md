---
title: Git Cheat Sheet
date: 2018-02-27
tags:
    - Git
    - Cheat Sheet
categories: 
    - tech
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
| `git log` | Lists version history for the current branch |
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

## 回退修改

- 回退工作区的修改：`git checkout -- <file>`
- 回退工作区的修改，但保存现场：`git stash`
    - 恢复现场：`git stash pop`
    - 查看保存的现场：`git stash list`
- 回退暂存区的修改到工作区：`git reset HEAD <file>`
- 回退版本库的修改到工作区：`git reset <commit>` 或 `git reset –-mixed <commit>`
- 回退版本库的修改到暂存区：`git reset –-soft <commit>`
- 回退版本库的修改（**不保留**）：`git reset --hard <commit>`
    - 如果错误执行了该回退操作，可以通过 `git reflog` 查看命令历史，命令历史中记载了回退前的 commit id，可以执行 `git reset --hard <commit>` 回退该回退操作
- 回退所有未被跟踪的文件：`git clean -df`

## 跟踪文件

- 强制跟踪指定文件：`git update-index --no-assume-unchanged <file>`
- 强制不跟踪指定文件：`git update-index --assume-unchanged <file>`

## Git 比较操作

- 比较工作区和暂存区的指定文件：`git diff <path>`
    - 比较所有文件：`git diff`
- 比较工作区和指定 commit 的指定文件：`git diff <commit> <path>`
    - 比较所有文件：`git diff <commit>`
- 比较暂存区和指定 commit 的指定文件：`git diff --cached <commit> <path>`
    - 比较暂存区和 `HEAD` 的指定文件：`git diff --cached <path>`
    - 比较所有文件：`git diff --cached <commit>`
- 比较 commit `A` 和 commit `B` 的指定文件：`git diff <A> <B> <path>`
    - 比较 `HEAD` 和 commit `B` 的指定文件：`git diff ..<B> <path>`
    - 比较 commit `A` 和 `HEAD` 的指定文件：`git diff <A>.. <path>`
- 比较 commit `A` 与 commit `B` 的 merge base 和 commit `B` 的指定文件：`git diff <A>...<B> <path>`
    - 比较 `HEAD` 与 commit `B` 的 merge base 和 commit `B` 的指定文件：`git diff ...<B> <path>`
    - 比较 commit `A` 与 `HEAD` 的 merge base 和 `HEAD` 的指定文件：`git diff <A>... <path>`
- 使用 difftool 比较文件，命令参数与 `git diff` 一致，但使用 `git difftool` 子命令
    - 配置 difftool：

        编辑 `~/.gitconfig`：

        ```
        [diff]
        	tool = meld
        [difftool "meld"]
        	path = C:\\path\\to\\meld\\Meld.exe
        ```

## Git 历史操作

- 查看分支合并图：`git log --graph`
- 配置 `git lg` 作为查看格式良好的历史记录的命令：

    ```
    [alias]
    	lg = log --color --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit
    ```

## Git 分支操作

- 查看当前分支：`git branch`
- 基于当前分支创建新分支：`git branch <name>`
    - 基于当前分支创建并切换到新分支：`git checkout -b <name>`
    - 基于指定分支创建并切换到新分支：`git checkout -b <name> <origin-branch>`
- 切换到指定分支：`git checkout <name>`
- 合并指定分支到当前分支：`git merge <name>`
    - 合并时在指定分支基础上重新提交当前分支从 merge base 开始的 commit：`git rebase -i <name>`
        - rebase 时历史会从旧到新显示，编辑历史时有如下 command 可用：
            - `pick`：直接入库
            - `edit`：在入库前允许重新编辑 commit
            - `reword`：在入库前允许重新编辑 commit message
            - `squash`：与前次提交进行 commit 合并
            - `fixup`：同 `squash`，但丢弃 commit message
        - 示例
            - 原始 log 如下：

                ```
                debug: commit1
                debug: commit2
                debug: commit3
                fix: commit4
                ```
            - 使用以下 command：

                ```
                pick debug: commit1
                fixup debug: commit2
                fixup debug: commit3
                squash fix: commit4
                ```
            - 结果：

                ```
                fix: commit4
                ```
        - 继续检查下个 commit：`git rebase --continue`
        - 取消本次 rebase：`git rebase --abort`
    - 使用指定工具进行 merge 操作：`git mergetool`
        - 配置 merge 工具：

            ```
            [merge]
            	tool = meld
            [mergetool "meld"]
            	path = C:\\path\\to\\meld\\Meld.exe
            ```
- 删除指定分支：`git branch -d <name>`
    - 删除未合并分支：`git branch -D <name>`

## Git 远程仓库操作

- 克隆远程仓库到当前目录：`git clone <repo-url>`
    - 克隆远程仓库到指定目录：`git clone <repo-url> <dir>`
        - `<dir>` 目录下会出现 `.git` 目录
- 关联远程仓库：`git remote add <repo-name> <repo-url>`
    - `<repo-name>` 惯例命名为 `origin`
    - `<repo-url>` 一般格式为 `git@server-name:path/repo-name.git`
- 查看远程仓库信息：`git remote -v`
- 拖取指定远程仓库：`git fetch <repo-name>`
- 拖取指定远程仓库的指定分支然后合并到当前分支：`git pull <repo-name> <branch-name>`
- 推送指定分支到指定远程仓库：`git push <repo-name> <branch-name>`
    - 推送当前分支到指定远程仓库：`git push <repo-name>`
    - 推送当前分支到上游仓库：`git push`
        - 要配置指定远程仓库为上游仓库，可以：
            - 在第一次推送时使用 `-u` 指定：`git push -u <repo-name> <branch-name>`
            - 直接配置：`git branch --set-upstream <branch-name> <repo-name>/<branch-name>`
- 删除指定远程仓库的指定分支：`git push <repo-name> :<branch-name>`
    - 如果由于远程仓库的 `HEAD` 指向待删除的分支而无法进行删除操作，可以先把 `HEAD` 指向其他分支，在远程仓库上进行以下操作：`git symbolic-ref HEAD refs/heads/<other-branch-name>`，在删除分支后再切换回来

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

## Git 配置

- 配置 committer：

    ```
    git config --global user.name <user-name>
    git config --global user.email <user-email>
    ```
- 让命令行输出显示颜色：`git config --global color.ui true`
- 让 non-bare repo 能被 push：`git config receive.denyCurrentBranch updateInstead`
- 让 Git 不要自动转换 CRLF：`git config --global core.autocrlf false`
- 让 Git 忽视文件的 mode 变化：`git config --global core.fileMode false`
- 为复杂操作配置别名：
    - 示例：

        ```
        [alias]
        	sy = "!f() { git status; git add .; git commit; git push origin-test ${1}; }; f"
        ```
- 配置 Git 的自动补全和命令行 prompt：

    在 `~/.bashrc` 中加入如下配置：

    ```
    source ${GIT_SOURCE_DIR}/contrib/completion/git-completion.bash
    source ${GIT_SOURCE_DIR}/contrib/completion/git-prompt.sh

    function color_my_prompt {
        local __user_and_host="\[\033[01;32m\]\u@\h"
        local __cur_location="\[\033[01;34m\]\w"
        local __git_branch_color="\[\033[31m\]"
        local __git_branch='`git branch 2> /dev/null | grep -e ^* | sed -E  s/^\\\\\*\ \(.+\)$/\(\\\\\1\)\ /`'
        local __prompt_tail="\[\033[35m\]$"
        local __last_color="\[\033[00m\]"
        export PS1="$__user_and_host $__cur_location $__git_branch_color$__git_branch$__prompt_tail$__last_color "
    }
    color_my_prompt
    ```

## Fun Facts

1. 在 Git 中，`HEAD` 表示当前版本，也就是最新的提交，上一个版本就是 `HEAD^`，上上一个版本就是 `HEAD^^`，上100个版本写成 `HEAD~100`。
2. 很多命令都有 `-n` 或 `--dry-run` 选项，使用了该选项后，命令不会直接运行，而是输出它将执行的内容，供用户判断执行的内容是否和预期一致，从而决定是否实际执行该命令。这避免了一些手误的情况，在某些重要的操作上很有用。
3. Git 的命令中常含有 `--`，它用来分割 Git 命令的选项和文件/文件列表，以防某些文件名被误认为是选项。


## Reference
[Git Cheat Sheet](http://uchuhimo.me/2017/04/18/git-cheat-sheet/)
