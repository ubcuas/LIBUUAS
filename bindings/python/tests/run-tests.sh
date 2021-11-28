#!/bin/bash

pip3 install -U pytest
cd /home/python-tests/
python3 -m pytest -s
exit