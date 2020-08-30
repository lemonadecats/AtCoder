TARGET_DIR=$(pwd -P)
if [ -e "${TARGET_DIR}/${1}" ]
then
	printf "\x1b[31mdirectory already exit !\x1b[39m\n"
	exit
fi
mkdir "${TARGET_DIR}/${1}"
cd "$(dirname "${0}")"
cp template.cpp "${TARGET_DIR}/${1}/A.cpp"
cp template.cpp "${TARGET_DIR}/${1}/B.cpp"
cp template.cpp "${TARGET_DIR}/${1}/C.cpp"
cp template.cpp "${TARGET_DIR}/${1}/D.cpp"
cp template.cpp "${TARGET_DIR}/${1}/E.cpp"
cp template.cpp "${TARGET_DIR}/${1}/F.cpp"
printf "\x1b[32mdirectory generated !\x1b[39m\n"
