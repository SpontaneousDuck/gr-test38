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

#ifndef INCLUDED_TEST38_MSGSTROBE_MM_IMPL_H
#define INCLUDED_TEST38_MSGSTROBE_MM_IMPL_H

#include <test38/msgStrobe_mm.h>

namespace gr {
  namespace test38 {

  class TEST38_API msgStrobe_mm_impl : public msgStrobe_mm
  {
  private:
    boost::shared_ptr<gr::thread::thread> d_thread;
    bool d_finished;
    long d_period_ms;
    pmt::pmt_t d_msg;
    const pmt::pmt_t d_port;

    void run();

  public:
    msgStrobe_mm_impl(pmt::pmt_t msg);
    ~msgStrobe_mm_impl();

    void set_msg(pmt::pmt_t msg) { d_msg = msg; }
    pmt::pmt_t msg() const { return d_msg; }

    // Overloading these to start and stop the internal thread that
    // periodically produces the message.
    bool start();
    bool stop();
    };

  } // namespace test38
} // namespace gr

#endif /* INCLUDED_TEST38_MSGSTROBE_MM_IMPL_H */

