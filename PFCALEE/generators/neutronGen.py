#!/usr/bin/env python
import math
import random
import optparse
import os

from time import strftime 

outDir = os.getcwd() 

usage = 'usage: %prog [options]'
parser = optparse.OptionParser(usage)
parser.add_option('-f', '--filename', dest='filename', help='lhe file name', default='myFile')
parser.add_option('-n', '--nevts', dest='nevts', help='number of events', default=100, type=int)
parser.add_option('-e', '--energy', dest='energy', help='energy of events in GeV', default=4, type=float)
(opt, args) = parser.parse_args()

lhefile = open('%s/%s.lhe'%(outDir,opt.filename), 'w')
lhefile.write('<header>\n')
lhefile.write('This file contains primary neutrons with user chosen energy and (x,y).\n')
lhefile.write('Do not edit this file manually.\n')
lhefile.write('File created on %s at %s\n'%(strftime('%Y-%m-%d'),strftime('%H:%M:%S')))
lhefile.write('</header>\n')

for i in range(0,opt.nevts):

    lhefile.write('<event>\n')
    
    x = random.uniform(-10,10)
    y = random.uniform(-10,10)
    
    lhefile.write('2112 %f %f -550 0 0 1 %d\n'%(x,y,opt.energy))

    lhefile.write('</event>\n')

lhefile.close()
