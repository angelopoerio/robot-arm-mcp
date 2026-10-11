import logging
import os

import serial
from fastmcp import FastMCP

logging.basicConfig(level=logging.INFO, filename="/tmp/robot-arm-mcp.log")
logger = logging.getLogger("robot_arm_mcp")

mcp = FastMCP("robot-arm-mcp")

SERIAL_PORT = os.environ.get("ROBOT_ARM_SERIAL_PORT", "/dev/ttyACM0")
SERIAL_BAUDRATE = int(os.environ.get("ROBOT_ARM_SERIAL_BAUDRATE", "9600"))
SER = serial.Serial(SERIAL_PORT, SERIAL_BAUDRATE)


@mcp.tool
def move_joint(joint_index: int, degree: int) -> str:
    """Move a robot arm joint to the given angle in degrees.

    Args:
        joint_index: The joint to move, in the range [0, 5].
        degree: The target angle in degrees, in the range [0, 180].
    """
    if not 0 <= joint_index <= 5:
        raise ValueError("joint_index must be between 0 and 5")
    if not 0 <= degree <= 180:
        raise ValueError("degree must be between 0 and 180")

    logger.info("move_joint called: joint_index=%s degree=%s", joint_index, degree)
    SER.write(f"{joint_index} {degree}".encode("ascii"))

    return f"Moved joint {joint_index} to {degree} degrees"


def main() -> None:
    logger.info("Using serial port %s at baud rate %s", SERIAL_PORT, SERIAL_BAUDRATE)
    mcp.run(transport="stdio")


if __name__ == "__main__":
    main()
