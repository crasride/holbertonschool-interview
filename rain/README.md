<h1 align="center">Rain</h1>

### Requirements
### General

* Allowed editors: `vi`, `vim`, `emacs`
* All your files will be interpreted/compiled on Ubuntu 14.04 LTS using `python3` (version 3.4.3)
* All your files should end with a new line
* The first line of all your files should be exactly `#!/usr/bin/python3`
* A `README.md` file, at the root of the folder of the project, is mandatory
* Your code should use the `PEP 8` style (version 1.7.x)
* You are not allowed to import any module
* All modules and functions must be documented
* All your files must be executable

## Tasks

### [0. Rain](./0-rain.py)
Given a list of non-negative integers representing walls of width 1, calculate how much water will be retained after it rains.

* Prototype:' `def rain(walls)`
* `walls` is a list of non-negative integers.
* Return: Integer indicating total amount of rainwater retained.
* Assume that the ends of the list (before index 0 and after index walls[-1]) are not walls, meaning they will not retain water.
* If the list is empty return `0`.
```
jesse@ubuntu:~/0x10$ cat 0_main.py
#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(rain(walls))

jesse@ubuntu:~/0x10$
jesse@ubuntu:~/0x10$ ./0_main.py
6
jesse@ubuntu:~/0x10$
```
Visual representation of the walls `[0, 1, 0, 2, 0, 3, 0, 4]`

<p align="left">
	<img width="400" height="175" src="../images/rain1.png" alt="C Logo">
</p>


Visual representation of the walls `[2, 0, 0, 4, 0, 0, 1, 0]`

<p align="left">
	<img width="400" height="175" src="../images/rain2.png" alt="C Logo">
</p>


### Repo:

* GitHub repository: `holbertonschool-interview`
* Directory: `rain`
* File: `0-rain.py`


