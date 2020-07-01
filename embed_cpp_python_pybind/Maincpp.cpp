#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#include <iostream>

namespace py = pybind11;

int main()
{
	//Initialize Python
	py::scoped_interpreter guard{};
	//Print command
	py::print("Program to execute Py script Through C++ Using Pybind\n");
	py::print("######################################################\n");
	//simple py command execution
	py::exec(R"(print("Hello world")
			)");
	//simple py line evaluation
	auto global = py::module::import("__main__").attr("__dict__");
	auto local = py::dict();
	py::eval<py::eval_single_statement>("from time import time,ctime",global,local);

	py::eval("print(ctime(time()))", global, local);

	//simple py script execution
	try
	{
		py::eval_file("D:\\pybind\\python_app_1\\PythonApplication1\\PythonApplication1.py",global);
	}
	catch (py::error_already_set const& pythonErr) { std::cout << pythonErr.what(); }
	


	return 0;
}
