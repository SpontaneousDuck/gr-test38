#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2020 gr-test38 author.
#
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
#

from gnuradio import gr, gr_unittest
from gnuradio import blocks
import pmt
import test38_swig as test38

class qa_msgStrobe_mm(gr_unittest.TestCase):

    def setUp(self):
        self.tb = gr.top_block()

    def tearDown(self):
        self.tb = None

    def test_001_t(self):
        text = "TESTING"
        msg = pmt.intern("TESTING")
        src = test38.msgPulse_mm(msg)
        snk = blocks.message_debug()

        self.tb.msg_connect(src, "strobe", snk, "store")
        self.tb.start()
        time.sleep(1)
        self.tb.stop()
        self.tb.wait()

        rec_msg = snk.get_message(0)
        self.assertTrue(pmt.eqv(rec_msg, msg))


if __name__ == '__main__':
    print 'Blocked waiting for GDB attach (pid = %d)' % (os.getpid(),)
    raw_input('Press Enter to continue: ')
    gr_unittest.run(qa_msgStrobe_mm)
