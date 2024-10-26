# GitHub workflow

## [Видео: Как да предадем задачите си в GitHub с Pull Request, използвайки GitHub Desktop](https://youtu.be/IeEsHCtohD4)

[![Как да предадем задачите си в GitHub с Pull Request, използвайки GitHub Desktop](https://img.youtube.com/vi/IeEsHCtohD4/0.jpg)](https://youtu.be/IeEsHCtohD4)

**0.** Star the repository
![image](images/star-repo.png)

**1.** Fork the repository

- [How to fork a repository.](https://docs.github.com/en/get-started/quickstart/fork-a-repo)

**2.** Clone the repository on your local machine

- [How to clone a repository.](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository)

- In GitHub desktop - Repository -> Repository settings... -> Fork behavior -> select To contribute to the parent repository
  ![repo menu](images/repository-settings-menu.png)

  _На снимката по-долу си представете, че пише StefanShivarov/introduction-to-programming-2024-25_

  ![repo-settings](images/repository-fork-settings.png)

**3.** Fetch origin

- ![fetch origin](images/fetch-origin.png)

**4.** Create a new branch

- The branch should be created from the master branch of the original repository. In this way you will always have the latest changes .
- [About branches.](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/about-branches)

- [How to create branch.](https://docs.github.com/en/desktop/contributing-and-collaborating-using-github-desktop/making-changes-in-a-branch/managing-branches#creating-a-branch)

**5.** Add a solution for a task

- Create a cpp file for each task.
- **The name of the file should be TaskXX.cpp where XX is the number of the task**<br> e.g. Task01.cpp, Task12.cpp etc.
- Copy your solution into the file.

**6.** Commit solution to a task

- Commit the file for the task.
- **Each task should be in seperate commit.**
- Upload a maximum of 3 tasks per request (could be 1 or 2)
- Repeat step 5. and 6. until you have 1-3 tasks in the new branch. <br />
  Then create a new branch and start from step 4.
- [About commits.](https://docs.github.com/en/desktop/contributing-and-collaborating-using-github-desktop/making-changes-in-a-branch/committing-and-reviewing-changes-to-your-project#about-commits)

**7.** Open Pull Request to the original repository to the master branch

- [How to create pull request.](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/creating-a-pull-request)
- The pull request should request to merge the changes of your branch in the fork to the master branch of the original repositor.
- **The title of the Pull Request should be:**

  ```
  Pract.\<number\>: Add \<first task number\> - \<last task number\> | \<name\>

  Example:
  Pract.03: Add Task 01 | John Doe
  ```

- **The description of the pull Request should be**

  ```
  \<name\> \<lastname\>
  \<major\> \<group\> \<fn\>

  Example:
  John Doe
  SI 2 2MI0600192
  ```
