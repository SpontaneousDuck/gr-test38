/* -*- c++ -*- */

#define TEST38_API

%include "gnuradio.i"           // the common stuff

//load generated python docstrings
%include "test38_swig_doc.i"

%{
#include "test38/msgStrobe_mm.h"
%}

%include "test38/msgStrobe_mm.h"
GR_SWIG_BLOCK_MAGIC2(test38, msgStrobe_mm);
