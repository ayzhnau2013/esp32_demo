#!/usr/bin/env python

from __future__ import division,print_function,unicode_literals

import ttfw_idf

@ttfw_idf.idf_example_test(env_tag='Example_GENERIC', target=['esp32', 'esp32s2', 'esp32c3'], ci_target=['esp32'])
def test_example_hello_world(env, extra_data) :
    app_name = "hello world"
    dut = env.get_dut(app_name,"00_STUDY")
    
