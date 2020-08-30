TARGET_DIR=$(pwd -P)
if [ -e "${TARGET_DIR}/${1}" ]
then
	printf "\x1b[31mdirectory already exit !\x1b[39m\n"
	exit
fi
mkdir "${TARGET_DIR}/${1}"
cd "$(dirname "${0}")"
cp tmplate.cpp "${TARGET_DIR}/${1}/A.cpp"
cp tmplate.cpp "${TARGET_DIR}/${1}/B.cpp"
cp tmplate.cpp "${TARGET_DIR}/${1}/C.cpp"
cp tmplate.cpp "${TARGET_DIR}/${1}/D.cpp"
cp tmplate.cpp "${TARGET_DIR}/${1}/E.cpp"
cp tmplate.cpp "${TARGET_DIR}/${1}/F.cpp"
printf "\x1b[32mdirectory generated !\x1b[39m\n"
