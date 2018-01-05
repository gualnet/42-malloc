# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_all.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfarrugi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/04 11:33:40 by tfarrugi          #+#    #+#              #
#    Updated: 2018/01/04 11:33:42 by tfarrugi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from os import listdir
from os import system 
from os import remove
from subprocess import Popen
from subprocess import PIPE
from time import sleep
import sys

exe = list()
error_file = "error.malloc"

def test_create():
    files = listdir()
    for i in files:
        if i[-1] is "c" and i[-2] is ".":
            name = i.split(".")[0]
            exe.append(name);
            Popen(["clang", "-o", name, i]);
    sleep(1);

def test_write_exe():
    system("echo \""+'\n'.join([x for x in exe])+"\" > exe_crafted");

def test_all():
    increase = 100 / len(exe);
    ebp = 0
    error = 0;
    try:
        remove("./{}".format(error_file))
    except:
        pass
    for i in exe:
        ebp += increase;
        sys.stdout.write("\r");
        sys.stdout.write("\033[32;1m{}     [{}%]\0\033[0m\033[K".format(i, ebp));
        sys.stdout.flush();
        output = Popen(["sh", "run.sh", "./{}".format(i)], stdout=PIPE, stderr=PIPE);
        stdout = output.stdout.read() 
        stderr = output.stderr.read() 
        try:
            assert stdout == b'';
            assert stderr == b'';
        except AssertionError:
            error = 1;
            with open("./{}".format(error_file), "a") as f:
                f.write("\033[31m{}     [{}%]:\n   stderr: [{}]\n   stdout: [{}]\033[0m\n".format(i, ebp, stderr, stdout));
    if error == 1:
        sys.stdout.write("\033[31;1m\nErrors occurs. There are in [{}] file.\033[0m".format(error_file))
    else:
        sys.stdout.write("\033[32;1m\nCongrat's.\033[0m")
def test_delete():
    for i in exe:
        remove("./{}".format(i));

if __name__ == "__main__":
    test_create()
    test_write_exe()
    test_all()
    test_delete()

