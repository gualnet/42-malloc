#  !/bin/sh

make -C ./tests/
# echo 'Make tests : ok\n'

# /usr/bin/time -l ./tests/test0
# echo 'test 0 : ok - (a vide)\n'

# /usr/bin/time -l ./tests/test1
# echo 'test 1 : ok - (malloc sys)\n'

# ./run.sh /usr/bin/time -l ./tests/test0
# echo 'test 0 : ok - (a vide)\n'

./run.sh /usr/bin/time -l ./tests/test1
# echo 'test 1 : ok - (malloc ft)\n'
