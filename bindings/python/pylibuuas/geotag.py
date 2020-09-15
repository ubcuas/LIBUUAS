import pylibuuas.uuaspb_pb2 as pylibuuaspb
import pylibuuas.telem as telem
import pylibuuas.libuuas as libuuas


def getImageGeotag(filename: str) -> pylibuuaspb.Telemetry:
    request = pylibuuaspb.UnGeoTagRequest()
    request.filename = filename
    response = libuuas.getImageGeotagRequest(request)
    return response.telemetry


def geotagImage(filename: str, telemetryArgs: telem.TelemetryArgs) -> bool:
    request = pylibuuaspb.GeoTagRequest()
    request.filename = filename
    request.telemetry.CopyFrom(telem.new_telem_msg(telemetryArgs))
    response = libuuas.geotagImageRequest(request)
    return response.result == pylibuuaspb.ResultStatus.OK
