# Design Patterns in Python

This Repository contains Python examples for all classic Gangs of Four design patterns.

Each pattern includes two examples:

- [x] **Conceptual** examples show the internal structure of patterns, including detailed comments.

- [ ] **RealWorld** examples show how patterns can be used in real-world Python applications.


## Requirements

These examples require Python 3.7 and newer.

All examples can be launched via the command line, using the Python executable as follows:

```sh
python src/Path-to-example/main.py
```

For the best experience, I recommend working with examples with these IDEs:

- [PyCharm](https://www.jetbrains.com/pycharm/)
- [Visual Studio Code](https://code.visualstudio.com/) with the [Python extension](https://marketplace.visualstudio.com/items?itemName=ms-python.python)

## FAQ

#### 1. What is the _Client Code_?

_Client_ means _client of classes, defined as part of a pattern_, which is merely a caller of the given methods or a user of the given classes. In other words, it's the part of your application's code that uses the pattern's classes.

#### 2. I don't understand the roles you're referring to in RealWorld examples.

Take a look at the conceptual example first. There you'll find detailed descriptions of each class in a pattern, its role, and connection to other classes.


## Contributor's Guide

I appreciate any help, whether it's a simple fix of a typo or a whole new example. Just [make a fork](https://help.github.com/articles/fork-a-repo/), make your change and submit a [pull request](https://help.github.com/articles/creating-a-pull-request-from-a-fork/).

Here's a style guide which might help you to keep your changes consistent with the rest of the project's code:

1. All code should match the [PEP 8 coding style guide](https://www.python.org/dev/peps/pep-0008/)

2. Try to hard-wrap the code at 80th's character. It helps to list the code on the website without scrollbars.

3. Aim to put all code within one file. Yes, I realize that it's not how it supposed to be done in production. However, it helps people to understand examples better, since all code fits into one screen.

4. Comments may or may not have language tags in them, such as this:

    ```python
    """
    EN: All products families have the same varieties (MacOS/Windows).

    This is a MacOS variant of a button.

    RU: Все семейства продуктов имеют одни и те же вариации (MacOS/Windows).

    Это вариант кнопки под MacOS.
    """
    ```
    
    This notation helps to keep the code in one place while allowing the website to generates separate versions of examples for all listed languages. Don't be scared and ignore the non-English part of such comments. If you want to change something in a comment like this, just do it. Even if you do it wrong, we'll tell you how to fix it during the Pull Request.


