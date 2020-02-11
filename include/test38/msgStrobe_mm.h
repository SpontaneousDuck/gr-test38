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

#ifndef INCLUDED_TEST38_MSGSTROBE_MM_H
#define INCLUDED_TEST38_MSGSTROBE_MM_H

#include <test38/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace test38 {

    /*!
     * \brief <+description of block+>
     * \ingroup test38
     *
     */
    class TEST38_API msgStrobe_mm : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<msgStrobe_mm> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of test38::msgStrobe_mm.
       *
       * To avoid accidental use of raw pointers, test38::msgStrobe_mm's
       * constructor is in a private implementation
       * class. test38::msgStrobe_mm::make is the public interface for
       * creating new instances.
       */
      static sptr make(pmt::pmt_t msg);

      /*!
     * Reset the message being sent.
     * \param msg The message to send as a PMT.
     */
      virtual void set_msg(pmt::pmt_t msg) = 0;

      /*!
     * Get the value of the message being sent.
     */
      virtual pmt::pmt_t msg() const = 0;
    };

  } // namespace test38
} // namespace gr

#endif /* INCLUDED_TEST38_MSGSTROBE_MM_H */

