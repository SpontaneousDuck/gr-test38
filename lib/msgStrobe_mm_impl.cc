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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "msgStrobe_mm_impl.h"
#include <string>

namespace gr {
  namespace test38 {

    msgStrobe_mm::sptr
    msgStrobe_mm::make(pmt::pmt_t msg)
    {
      return gnuradio::get_initial_sptr
        (new msgStrobe_mm_impl(msg));
    }


    /*
     * The private constructor
     */
    msgStrobe_mm_impl::msgStrobe_mm_impl(pmt::pmt_t msg)
      : gr::block("msgStrobe_mm",
          io_signature::make(0, 0, 0), io_signature::make(0, 0, 0)),
          d_finished(false),
          d_msg(msg),
          d_port(pmt::mp("strobe")),
          d_period_ms(500)
    {
      message_port_register_out(d_port);

      message_port_register_in(pmt::mp("set_msg"));
      set_msg_handler(pmt::mp("set_msg"),
                      boost::bind(&msgStrobe_mm_impl::set_msg, this, _1));
    }

    /*
     * Our virtual destructor.
     */
    msgStrobe_mm_impl::~msgStrobe_mm_impl()
    {
    }

    bool msgStrobe_mm_impl::start()
    {
      // NOTE: d_finished should be something explicitly thread safe. But since
      // nothing breaks on concurrent access, I'll just leave it as bool.
      d_finished = false;
      d_thread = boost::shared_ptr<gr::thread::thread>(
          new gr::thread::thread(boost::bind(&msgStrobe_mm_impl::run, this)));

      return block::start();
    }

    bool msgStrobe_mm_impl::stop()
    {
      // Shut down the thread
      d_finished = true;
      d_thread->interrupt();
      d_thread->join();

      return block::stop();
    }

    void msgStrobe_mm_impl::run()
    {
      while (!d_finished)
      {
        boost::this_thread::sleep(
            boost::posix_time::milliseconds(static_cast<long>(d_period_ms)));
        if (d_finished)
        {
          return;
        }

        message_port_pub(d_port, d_msg);
      }
    }
  } /* namespace test38 */
} /* namespace gr */

