# Linux-Shell-in-C

commands format:

Internal:******************************************************************************************************************
cd ..
cd -
cd [address]

echo -e [text]
echo -E [text]
echo [text]

pwd
pwd -L
pwd -P


External:*******************************************************************************************************************
ls
ls -r
ls -a

cat filename
cat -n filename
cat -E filename

mkdir file_addr
mkdir -v [directories]
mkdir -p [file_addr]

date (NORMAL TIME!)
date +%D
date -u (UTC TIME)                           


rm [filenames with spaces(if exist!)]
rm -v [filenames]
rm -r [filenames]

FOR THREAD EXECUTION, just enter "&t" at the end of commands and thread execution of commands will be done

TESTCASE: 

echo
echo helloworld
echo hello\nworld
echo "hello\nworld"
echo -E "hello\nworld"
echo -e "hello\nworld\tin the \csky"

pwd
cd
pwd
cd Desktop
cd Desktop
cd assignment1
pwd -p
pwd -L
cd ..
cd -
pwd
cd -
pwd
cd -
pwd

cd
cd /
pwd
cd
cd Desktop/assignment1

date
date -u
date +%D

mkdir first second
mkdir -v third fourth first
mkdir -p first/second
mkdir -p fifth/sixth/seventh

cat [file1] [file2]
cat -n [file1] [file2]
cat -E [file1] [file2]

ls
ls -a
ls -r

rm -r first second third fourth fifth
rm -v [filenames]
rm [filenames]

FOR THREAD EXECUTION COMMANDS JUST END THE EXTERNAL COMMANDS WITH "&t" in the testcase
