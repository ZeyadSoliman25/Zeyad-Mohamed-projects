from setuptools import setup

APP = ["main.py"]
OPTIONS = {
    "argv_emulation": True,
}

setup(
    app = APP,
    options=OPTIONS,
    setup_requires=["py2app"]
)