# 42 School Monorepo — Testing & CI Guide

This guide explains how to write, execute, and automate tests across projects in this repository, both **locally** and in the **GitHub Actions CI pipeline**.

---

## 1. 🎯 Testing Philosophy

* **Safety**: Tests live inside `tests/` folders and never interfere with official 42 compilation rules (`all`, `clean`, `fclean`, `re`).
* **Norm Exemption**: Test files are deliberately exempt from Norminette rules so you can use standard assertion libraries, `printf`, and comprehensive testing logic.
* **Selectivity**: You can choose to run tests for only the specific project you are actively modifying, avoiding slow, bloated test cycles.

---

## 2. 💻 Running Tests Locally

### Run Tests for a Specific Project
From the repository root:
```bash
make test PROJECT=libft
# or
make test-libft
```

Inside the project directory directly:
```bash
cd r00/libft
make test
```

### Clean Up Test Artifacts
```bash
make fclean-all
```

---

## 3. 🤖 Automated Testing in GitHub Actions CI

Whenever you push code or open a Pull Request, GitHub Actions checks which files changed:
* If you modified files in `r00/libft/**`, it triggers the **Libft Test Job**.
* If you modified files in `r03/minishell/**`, it triggers the **Minishell Test Job**.
* Projects you didn't touch are **automatically skipped** to keep CI fast and efficient.

### Manual Test Execution via GitHub UI
You can manually run tests for any project from the GitHub Actions dashboard:
1. Go to your repository on GitHub.
2. Click **Actions** > **Project Test Runner**.
3. Click **Run workflow** and select the project you want to test from the dropdown menu (`libft`, `minishell`, `push_swap`, or `all`).

---

## 4. 📝 How to Add Tests to a New Project

To add automated tests to any project (e.g. `r02/push_swap` or `r03/minishell`):

1. **Create the `tests/` directory**:
   ```bash
   mkdir -p rXX/<project>/tests
   ```
2. **Add your test script or runner**:
   * For C unit tests: `rXX/<project>/tests/testMain.c`
   * For integration/shell tests: `rXX/<project>/tests/testRunner.sh`
3. **Add a `test` target in that project's Makefile**:
   ```makefile
   test: all
   	@bash tests/testRunner.sh
   ```
4. **Ensure `fclean` removes test outputs**:
   ```makefile
   fclean: clean
   	$(RM) $(NAME) testRunner
   ```
