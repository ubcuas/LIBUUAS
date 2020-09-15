import pytest
import shutil
import os

from pylibuuas.geotag import getImageGeotag, geotagImage
from pylibuuas.telem import TelemetryArgs


@pytest.fixture
def test_telemetryArgs():
    targs = TelemetryArgs(
        latitude=1.0,
        longitude=2.0,
        altitude_agl_m=3.0,
        altitude_msl_m=4.0,
        heading_deg=5.0,
        velocityx_m_s=6.0,
        velocityy_m_s=7.0,
        velocityz_m_s=8.0,
        roll_rad=9.0,
        pitch_rad=10.0,
        yaw_rad=11.0,
        rollspeed_rad_s=12.0,
        pitchspeed_rad_s=13.0,
        yawspeed_rad_s=14.0,
        timestamp_pixhawk_ms=15,
        timestamp_msg_ms=16,
    )
    return targs


@pytest.fixture
def tagged_image_filename():
    SRC_IMAGE_FILENAME = "tests/resources/images/tagged_image1.jpg"
    TARGET_IMAGE_FILENAME = "/tmp/tests/resources/images/tagged_image1.jpg"
    os.makedirs("/tmp/tests/resources/images/", exist_ok=True)
    shutil.copy2(SRC_IMAGE_FILENAME, TARGET_IMAGE_FILENAME)
    return TARGET_IMAGE_FILENAME


@pytest.fixture
def untagged_image_filename():
    SRC_IMAGE_FILENAME = "tests/resources/images/image1.jpg"
    TARGET_IMAGE_FILENAME = "/tmp/tests/resources/images/untagged_image1.jpg"
    os.makedirs("/tmp/tests/resources/images/", exist_ok=True)
    shutil.copy2(SRC_IMAGE_FILENAME, TARGET_IMAGE_FILENAME)
    return TARGET_IMAGE_FILENAME


def test_getImageGeotag(tagged_image_filename):
    telem = getImageGeotag(tagged_image_filename)
    assert telem.latitude == 1.0
    assert telem.longitude == 2.0
    assert telem.altitude_agl_m == 3.0
    assert telem.altitude_msl_m == 4.0
    assert telem.heading_deg == 5.0
    assert telem.velocityx_m_s == 6.0
    assert telem.velocityy_m_s == 7.0
    assert telem.velocityz_m_s == 8.0
    assert telem.roll_rad == 9.0
    assert telem.pitch_rad == 10.0
    assert telem.yaw_rad == 11.0
    assert telem.rollspeed_rad_s == 12.0
    assert telem.pitchspeed_rad_s == 13.0
    assert telem.yawspeed_rad_s == 14.0
    assert telem.timestamp_pixhawk_ms == 15
    assert telem.timestamp_msg_ms == 16


def test_geotagImage(untagged_image_filename, test_telemetryArgs):
    result = geotagImage(untagged_image_filename, test_telemetryArgs)
    assert result == True


def test_imageGeotagThenGetImageGeotag(untagged_image_filename, test_telemetryArgs):
    result = geotagImage(untagged_image_filename, test_telemetryArgs)
    assert result == True

    telem = getImageGeotag(untagged_image_filename)
    assert telem.latitude == test_telemetryArgs.latitude
    assert telem.longitude == test_telemetryArgs.longitude
    assert telem.altitude_agl_m == test_telemetryArgs.altitude_agl_m
    assert telem.altitude_msl_m == test_telemetryArgs.altitude_msl_m
    assert telem.heading_deg == test_telemetryArgs.heading_deg
    assert telem.velocityx_m_s == test_telemetryArgs.velocityx_m_s
    assert telem.velocityy_m_s == test_telemetryArgs.velocityy_m_s
    assert telem.velocityz_m_s == test_telemetryArgs.velocityz_m_s
    assert telem.roll_rad == test_telemetryArgs.roll_rad
    assert telem.pitch_rad == test_telemetryArgs.pitch_rad
    assert telem.yaw_rad == test_telemetryArgs.yaw_rad
    assert telem.rollspeed_rad_s == test_telemetryArgs.rollspeed_rad_s
    assert telem.pitchspeed_rad_s == test_telemetryArgs.pitchspeed_rad_s
    assert telem.yawspeed_rad_s == test_telemetryArgs.yawspeed_rad_s
    assert telem.timestamp_pixhawk_ms == test_telemetryArgs.timestamp_pixhawk_ms
    assert telem.timestamp_msg_ms == test_telemetryArgs.timestamp_msg_ms
