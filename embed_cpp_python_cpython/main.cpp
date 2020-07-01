#include <Python.h>

int main(int arg, char *argv[])
{
    Py_Initialize();

    //To Run Simple String Py Script Command
    PyRun_SimpleString(
        "print ('Program to execute Py script Through C++ Using Cython')\n"); 

    PyRun_SimpleString(
        "print ('#########################################')\n");

    PyRun_SimpleString("from time import time,ctime\n"
        "print ('Today is',ctime(time()))\n");

    PyObject* obj = Py_BuildValue("s", "D:\\pybind\\python_app_1\\PythonApplication1\\PythonApplication1.py");
    FILE *fp = _Py_fopen_obj(obj, "r+");
    if (fp != NULL) {
        //To execute Py script File
        PyRun_SimpleFile(fp, "D:\\pybind\\python_app_1\\PythonApplication1\\PythonApplication1.py");
    }
    Py_Finalize();
    return 0;
}