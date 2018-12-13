#!/bin/bash

# Copyright (c) 2018 Tim Perkins

# Update QMK and its submodules
git submodule sync --recursive
git submodule update --init --recursive
