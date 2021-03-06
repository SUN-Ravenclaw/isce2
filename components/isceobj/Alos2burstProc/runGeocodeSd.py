#
# Author: Cunren Liang
# Copyright 2015-present, NASA-JPL/Caltech
#

import os
import logging
import numpy as np

import isceobj
from isceobj.Alos2Proc.runGeocode import geocode
from isceobj.Alos2Proc.Alos2ProcPublic import getBboxGeo

logger = logging.getLogger('isce.alos2insar.runGeocodeSd')

def runGeocodeSd(self):
    '''geocode final products
    '''
    catalog = isceobj.Catalog.createCatalog(self._insar.procDoc.name)
    self.updateParamemetersFromUser()

    masterTrack = self._insar.loadTrack(master=True)
    #slaveTrack = self._insar.loadTrack(master=False)

    demFile = os.path.abspath(self._insar.demGeo)

    sdDir = 'sd'
    os.makedirs(sdDir, exist_ok=True)
    os.chdir(sdDir)

    if self.geocodeListSd == None:
        geocodeList = self._insar.multilookCoherenceSd + self._insar.azimuthDeformationSd + self._insar.maskedAzimuthDeformationSd
    else:
        geocodeList = self.geocodeListSd

    if self.bbox == None:
        bbox = getBboxGeo(masterTrack)
    else:
        bbox = self.bbox
    catalog.addItem('geocode bounding box', bbox, 'runGeocodeSd')

    numberRangeLooks = self._insar.numberRangeLooks1 * self._insar.numberRangeLooksSd
    numberAzimuthLooks = self._insar.numberAzimuthLooks1 * self._insar.numberAzimuthLooksSd

    for inputFile in geocodeList:
        if self.geocodeInterpMethodSd == None:
            img = isceobj.createImage()
            img.load(inputFile + '.xml')
            if img.dataType.upper() == 'CFLOAT':
                interpMethod = 'sinc'
            else:
                interpMethod = 'bilinear'
        else:
            interpMethod = self.geocodeInterpMethodSd.lower()

        geocode(masterTrack, demFile, inputFile, bbox, numberRangeLooks, numberAzimuthLooks, interpMethod, 0, 0)


    os.chdir('../')

    catalog.printToLog(logger, "runGeocodeSd")
    self._insar.procDoc.addAllFromCatalog(catalog)

