# About

An [MCP server](https://modelcontextprotocol.io) to control a simple [robot arm](https://github.com/angelopoerio/robot_project/)

# How to setup

* load the code in **ardino_code/code.c** to your arduino board, be sure to change it to fit your local requirements
* add the mcp server to Claude by running (in the current directory): **claude mcp add robot-arm-mcp -- uv run robot-arm-mcp**. Be sure to check the MCP server is using the right serial port to talk to the arduino board 
* when in Claude use the slash command **/mcp** to check the MCP service is correctly added and the **move_joint** tool is available to your chosen LLM model

# How to control the arm 

You can issue direct prompts like **"Move the joint 1 of 30 degrees"** or play with more complex behaviours for example: **"Move the joint 0 of 30 degrees when you want to answer NO, move the joint 3 of 30 degrees to answer YES"**. Ask any binary question to claude and you should see the arm moving accordingly
