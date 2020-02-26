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

#ifndef INCLUDED_TEST38_SYNC_TEST_H
#define INCLUDED_TEST38_SYNC_TEST_H

#include <test38/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace test38 {

    /*!
     * \brief <+description of block+>
     * \ingroup test38
     *
     */
    class TEST38_API sync_test : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<sync_test> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of test38::sync_test.
       *
       * To avoid accidental use of raw pointers, test38::sync_test's
       * constructor is in a private implementation
       * class. test38::sync_test::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace test38
} // namespace gr

#endif /* INCLUDED_TEST38_SYNC_TEST_H */

