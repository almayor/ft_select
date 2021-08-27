#!/bin/sh
# This program is needed primarily because the Norme
# (the code standard @ School 42) restricts the comment format to the one that
# isn't recognised by Doxygen. Hence, a pre-processing with perl is needed.
# This script also performs post-doxygen clean-up.

command -v doxygen >/dev/null
if [ $? -ne 0 ]; then
	echo "Please install Doxygen!"
else
	find src -type f \
		-exec sed -i '1s#^#///\\file\n#' {} \; \
		-exec perl -i -pe 's#^\/\*$#/\*\*#' {} \;
	sed -i '1s#^#///\\file\n#' libft.h
	perl -i -pe 's#^\/\*$#/\*\*#' libft.h
	doxygen docs/.doxygen/Doxyfile
	find src -type f \
		-exec sed -i '1d' {} \; \
		-exec perl -i -pe 's#^\/\*\*$#/\*#' {} \;
	sed -i '1d' libft.h
	perl -i -pe 's#^\/\*\*$#/\*#' libft.h
fi
