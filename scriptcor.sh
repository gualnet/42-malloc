#  !/bin/sh

make
make -C ./tests/
echo 'Makefile : ok\n'

sh run.sh /usr/bin/time -l ./tests/_test0
echo 'test 0 : ok - (a vide)\n'

sh run.sh /usr/bin/time -l ./tests/_test1
echo 'test 1 : ok - \n'

./run.sh /usr/bin/time -l ./tests/_test2
echo 'test 2 : ok -\n'

# ./run.sh /usr/bin/time -l ./tests/_test3
# echo 'test 3 : ok - (malloc ft)\n'
