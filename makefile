# for some version of MSVC
keyrate.exe: keyrate.c
	cl /Fe$@ /DWIN32_LEAN_AND_MEAN /O1 /Oa /Og /Os /Oy /Oi user32.lib $?
