/* -*- c++ -*- */
/*
 * Copyright 2020 gr-test38 author.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_TEST38_SYNC_TEST_IMPL_H
#define INCLUDED_TEST38_SYNC_TEST_IMPL_H

#include <test38/sync_test.h>

namespace gr {
  namespace test38 {

    class sync_test_impl : public sync_test
    {
     private:
      // Nothing to declare in this block.

     public:
      sync_test_impl();
      ~sync_test_impl();

      // Where all the action really happens
      int work(
              int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items
      );
    };

  } // namespace test38
} // namespace gr

#endif /* INCLUDED_TEST38_SYNC_TEST_IMPL_H */

