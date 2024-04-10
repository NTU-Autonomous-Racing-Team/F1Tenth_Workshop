import os
from glob import glob
from setuptools import setup

package_name = "pub_sub"

setup(
    name=package_name,
    version="0.0.0",
    packages=[package_name],
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
        (
            os.path.join("share", package_name, "launch"),
            glob(os.path.join("launch", "*launch.[pxy][yma]*")),
        ),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="luthov15",
    maintainer_email="luthov15@todo.todo",
    description="TODO: Package description",
    license="TODO: License declaration",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": [
            "minimal_publisher = pub_sub.minimal_publisher:main",
            "minimal_subscriber = pub_sub.minimal_subscriber:main",
        ],
    },
)
