#!/usr/bin/env python
import os
#-------------------------------------------------------------------------------
# DEFINES
#-------------------------------------------------------------------------------
SOLUTION = "MyBot"
SRC_DIR = "./src"
COMPILE_OPTIONS = "-g -O0 -Wall"
LINK_OPTIONS = ""
#-------------------------------------------------------------------------------
# FUNCTIONS
#-------------------------------------------------------------------------------
def CompOpt_AddIncDir (
	compile_options, 
	dir_to_add
):
	compile_options += "-I" + dir_to_add + " "
#-------------------------------------------------------------------------------
def IsFileSource (file_):
	path,ext = os.path.splitext (file_)
	if ext == ".c":
		return True
	return False
#-------------------------------------------------------------------------------
def ListToStr (list_):
	str_ = ""
	for i in list_:
		str_ += str(i) + " "
	return str_
#-------------------------------------------------------------------------------
def CompileFile (
	file_, 
	compile_options
):
	compiler_cmd_line = "gcc -c " + compile_options + " " + file_
	print "\tCC " + compiler_cmd_line
	ret_code = os.system (compiler_cmd_line)
	if ret_code != 0:
		print "Compile FAILS"
		return False
	return True
#-------------------------------------------------------------------------------
def LinkFiles (
	obj_files, 
	link_options,
	solution_name
):
	link_cmd_line = "gcc " + "-o " + solution_name + " " + \
	                 link_options + " " + ListToStr (obj_files)
	print "\tLN " + link_cmd_line
	ret_code = os.system (link_cmd_line)
	if ret_code != 0:
		print "Link FAILS"
		return False
	return True

#-------------------------------------------------------------------------------
def ExtractObjName (file_):
	path,ext = os.path.splitext (file_)
	path += ".o"
	return path
#-------------------------------------------------------------------------------
def CompileAndMakeSources (
	directory, 
	compile_options,
	link_options,
	solution_name
):
	obj_files = []
	for file_ in os.listdir (directory):
		if not IsFileSource (file_):
			continue
		filename = directory + "/" + file_
		ret_code = CompileFile (filename, compile_options)
		if ret_code == False:
			return False
		obj_file_name = ExtractObjName (file_)
		obj_files.append (obj_file_name);
	ret_code = LinkFiles (obj_files, link_options, solution_name)
	return ret_code
#-------------------------------------------------------------------------------
# MAIN
#-------------------------------------------------------------------------------
if __name__ == "__main__":
	compile_options = COMPILE_OPTIONS
	CompOpt_AddIncDir (compile_options, SRC_DIR)
	CompileAndMakeSources(SRC_DIR, compile_options, LINK_OPTIONS, SOLUTION);

