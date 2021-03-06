//#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//#
//# Author: Piyush Agram
//# Copyright 2013, by the California Institute of Technology. ALL RIGHTS RESERVED.
//# United States Government Sponsorship acknowledged.
//# Any commercial use must be negotiated with the Office of Technology Transfer at
//# the California Institute of Technology.
//# This software may be subject to U.S. export control laws.
//# By accepting this software, the user agrees to comply with all applicable U.S.
//# export laws and regulations. User has the responsibility to obtain export licenses,
//# or other export authority as may be required before exporting such information to
//# foreign countries or providing access to foreign persons.
//#
//#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef enu2losmodule_h
#define enu2losmodule_h

#include <Python.h>

extern "C"
{
    PyObject* createENU2LOS_C(PyObject *, PyObject *);
    PyObject* destroyENU2LOS_C(PyObject *, PyObject *);
    PyObject* enu2los_C(PyObject *, PyObject *);
    PyObject* setGeoDims_C(PyObject *, PyObject *);
    PyObject* setDims_C(PyObject *, PyObject *);
    PyObject* setWavelength_C(PyObject *, PyObject *);
    PyObject* setScaleFactor_C(PyObject *, PyObject *);
    PyObject* setLatitudeInfo_C(PyObject *, PyObject *);
    PyObject* setLongitudeInfo_C(PyObject *, PyObject *);
}

static PyMethodDef enu2los_methods[] =
{
    {"createENU2LOS", createENU2LOS_C, METH_VARARGS, " "},
    {"destroyENU2LOS", destroyENU2LOS_C, METH_VARARGS, " "},
    {"enu2los", enu2los_C, METH_VARARGS, " "},
    {"setGeoDims", setGeoDims_C, METH_VARARGS, " "},
    {"setDims", setDims_C, METH_VARARGS, " "},
    {"setWavelength", setWavelength_C, METH_VARARGS, " "},
    {"setScaleFactor", setScaleFactor_C, METH_VARARGS, " "},
    {"setLatitudeInfo", setLatitudeInfo_C, METH_VARARGS, " "},
    {"setLongitudeInfo", setLongitudeInfo_C, METH_VARARGS, " "},
    {NULL, NULL, 0 , NULL}
};
#endif //enu2losmodule_h
