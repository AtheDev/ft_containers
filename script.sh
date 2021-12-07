#!/usr/bin/env bash

CC="clang++"
CFLAGS="-Wall -Werror -Wextra -std=c++98"
SRCS="main.cpp test_vector.cpp test_map.cpp test_stack.cpp test_pair.cpp test_algorithm.cpp test_reverse_iterator.cpp"

compile() {
#$1 = ft/std
#$2 = executable bin_ft/bin_stl

    $CC $CFLAGS -D NS=$1 -o $2 $SRCS
}


test_dir="diff"
if [[ ! -d "$test_dir" ]]; then
    mkdir $test_dir
fi
test_file=`ls "test"`
for file in ${test_file[@]}; do
    cp test/$file $test_dir/$file
    sed -i 's/  std::cin.get();/\/*std::cin.get();*\//g' $test_dir/$file
done
cd diff
compile "ft" "bin_ft"
compile "std" "bin_stl"
/usr/bin/time -o time_ft.txt ./bin_ft 2> /dev/null 1> bin_ft.log
/usr/bin/time -o time_stl.txt ./bin_stl 2> /dev/null 1> bin_stl.log
diff bin_stl.log bin_ft.log >diff.log;

echo ;