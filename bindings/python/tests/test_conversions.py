import pytest

import pylibuuas.conversions


def test_f_2_m():
    result = pylibuuas.conversions.f_2_m(10)

    assert round(result, 3) == 3.048


def test_feet_to_meter():
    result = pylibuuas.conversions.feet_to_meter(10)

    assert round(result, 3) == 3.048


def test_m_2_f():
    result = pylibuuas.conversions.m_2_f(10)

    assert round(result, 3) == 32.808


def test_meter_to_feet():
    result = pylibuuas.conversions.m_2_f(10)

    assert round(result, 3) == 32.808


def test_ll_to_utm():
    result = list(pylibuuas.conversions.ll_to_utm(100.223, 76.232))
    result[0] = round(result[0], 3)
    result[1] = round(result[1], 3)

    assert result == [532488.597, 8461409.729]


def test_utm_to_ll():
    result = list(pylibuuas.conversions.utm_to_ll(120000, 120000))
    result[0] = round(result[0], 3)
    result[1] = round(result[1], 3)

    assert result == [95.586, 1.084]
