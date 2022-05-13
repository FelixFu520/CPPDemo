#pragma once

// numpy_demo.cpp 
#include <Python.h> 
#include <iostream>
#include <numpy/arrayobject.h>
using namespace std;

int main_numpy(int argc, char *argv[])
{
	wchar_t *program = Py_DecodeLocale(argv[0], NULL);
	if (program == NULL) {
		fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
		exit(1);
	}
	Py_SetProgramName(program);  /* optional but recommended */
	Py_Initialize();

	import_array();		/* load numpy api */
	double array_1[2][3] = { { 2,5,6 },{ 5,6,5 } };
	double array_111[2][2][3] = { { { 2,5,6 },{ 5,6,5 } },{ { 2,5,6 },{ 5,6,5 } } };
	npy_intp dims_1[] = { 2, 3 };
	PyObject *mat_1 = PyArray_SimpleNewFromData(2, dims_1, NPY_DOUBLE, array_1);

	double array_2[3][4] = { { 1,3,0,4 },{ 2,2,5,3 },{ 1,2,1,4 } };
	npy_intp dims_2[] = { 3, 4 };
	PyObject *mat_2 = PyArray_SimpleNewFromData(2, dims_2, NPY_DOUBLE, array_2);

	PyObject *prod = PyArray_MatrixProduct(mat_1, mat_2);

	PyArrayObject *mat_3;
	PyArray_OutputConverter(prod, &mat_3);
	npy_intp *shape = PyArray_SHAPE(mat_3);
	double *array_3 = (double*)PyArray_DATA(mat_3);

	cout << "numpy result:\n";
	for (int i = 0; i < shape[0]; i++) {
		for (int j = 0; j < shape[1]; j++) {
			cout << array_3[i*shape[1] + j] << "\t";
		}
		cout << endl;
	}
	cout << "\nC result:\n";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			double t = 0;
			for (int k = 0; k < 3; k++)
				t += array_1[i][k] * array_2[k][j];
			cout << t << "\t";
		}
		cout << endl;
	}

	if (Py_FinalizeEx() < 0) {
		exit(120);
	}
	PyMem_RawFree(program);
	getchar();
	return 0;
}