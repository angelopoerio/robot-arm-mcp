# Overview

This file provides guidance to implement a python MCP server to control a 5 joints robot arm

## Critical rules

* Must Use python3 and the libraries fastmcp and serial
* The server use the STDIO transport
* The default serial port is /dev/ttyACM0 and the default baud rate is 9600
* The server must log at startup the used serial port and baud rate and each time the tool is called. Log to the file /tmp/robot-arm-mcp.log
* The MCP server must expose one tool
   * the tool must take two input parameters
     * an index number representing the joint (it must be contained in [0,5])
     * the degree to move the joint (it must be in [0,180])
     * the tool must send to a configurable serial port one line containing the index number, one space and the degree  

## Development rules

* always use the uv package manager
* always run the black python3 linting tool after editing a file

