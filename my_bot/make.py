#!/usr/bin/env python
import os
import sys
#-------------------------------------------------------------------------------
# DEFINES
#-------------------------------------------------------------------------------
COMPILE_OPTIONS = "-g -O0 -Wall"
LINK_OPTIONS = ""
#-------------------------------------------------------------------------------
# FUNCTIONS
#-------------------------------------------------------------------------------
def CompOpt_AddIncDirs (
	compile_options, 
	dirs_to_add
):
	for dir_ in dirs_to_add:
		compile_options += "-I" + dir_ + " "
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
def CompileFilesInDir (
	directory, 
	compile_options
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
	return obj_files
#-------------------------------------------------------------------------------
def CompileAndMakeSources (
	directories, 
	compile_options,
	link_options,
	solution_name
):
	obj_files = []
	CompOpt_AddIncDirs (compile_options, directories)
	for dir_ in directories:
		obj_files_dir = CompileFilesInDir (dir_, compile_options)
		for obj_file_ in obj_files_dir:
			obj_files.append (obj_file_)
	ret_code = LinkFiles (obj_files, link_options, solution_name)
	return ret_code
#-------------------------------------------------------------------------------
# MAIN
#-------------------------------------------------------------------------------
def PrintUsage () :
	print "Usage: make.py solution_name src_dir1 [src_dir2] ... [src_dirN]"
#-------------------------------------------------------------------------------
if __name__ == "__main__":
	if len (sys.argv) < 3:
		PrintUsage ()
		exit (-1)
	solution = sys.argv[1]
	src_dirs = sys.argv[2:]
	compile_options = COMPILE_OPTIONS
	CompileAndMakeSources (
		src_dirs, 
		compile_options, 
		LINK_OPTIONS, 
		solution
	);

