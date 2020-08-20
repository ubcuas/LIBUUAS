import cppyy
import pylibuuas.uuaspb_pb2 as pylibuuaspb
from array import array

cppyy.include('libuuas/bindings.hpp')
cppyy.load_library('/usr/local/lib/libuuas.so')


def getImageGeotagRequest(request: pylibuuaspb.UnGeoTagRequest) -> pylibuuaspb.UnGeoTagResponse:
    pbbufferStr = request.SerializeToString()
    pbbuffer = array('B', [b for b in pbbufferStr])
    length = len(pbbuffer)

    resppbbuffer = array('B', [0 for _ in range(512)])
    resplength = len(resppbbuffer)

    respBytes = cppyy.gbl.getImageGeotagRequest(
        pbbuffer, length, resppbbuffer, resplength)

    resppbbufferStr = resppbbuffer.tobytes()[:respBytes]
    response = pylibuuaspb.UnGeoTagResponse()
    response.ParseFromString(resppbbufferStr)
    return response


def geotagImageRequest(request: pylibuuaspb.GeoTagRequest) -> pylibuuaspb.GeoTagResponse:
    pbbufferStr = request.SerializeToString()
    pbbuffer = array('B', [b for b in pbbufferStr])
    length = len(pbbuffer)

    resppbbuffer = array('B', [0 for _ in range(512)])
    resplength = len(resppbbuffer)

    respBytes = cppyy.gbl.geotagImageRequest(
        pbbuffer, length, resppbbuffer, resplength)

    resppbbufferStr = resppbbuffer.tobytes()[:respBytes]
    response = pylibuuaspb.GeoTagResponse()
    response.ParseFromString(resppbbufferStr)
    return response


def orderedRouteRequest(request: pylibuuaspb.OrderedRouteRequest) -> pylibuuaspb.OrderedRouteResponse:
    pbbufferStr = request.SerializeToString()
    pbbuffer = array('B', [b for b in pbbufferStr])
    length = len(pbbuffer)

    resppbbuffer = array('B', [0 for _ in range(2048)])
    resplength = len(resppbbuffer)

    respBytes = cppyy.gbl.orderedRouteRequest(
        pbbuffer, length, resppbbuffer, resplength)

    resppbbufferStr = resppbbuffer.tobytes()[:respBytes]
    response = pylibuuaspb.OrderedRouteResponse()
    response.ParseFromString(resppbbufferStr)
    return response
