#include <Python.h>
#include <stdio.h>

/**
 * print_python_list_info - prints some basic info about python lists
 * @p: pointer to PyObject object/list
 *
 * Return: no return value (void)
 */
void print_python_list_info(PyObject *p)
{
  PyObject *obj;
  long int i = 0, len = 0;

  len = PyList_Size(p);
  if (PyList_Check(p))
    {
      printf("[*] Size of the Python List = %ld\n", len);
      printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);
    }

  while (i < len)
    {
      obj = PyList_GetItem(p, i);
      printf("Element %ld: %s\n", i, Py_TYPE(obj)->tp_name);
      i++;
    }
}
