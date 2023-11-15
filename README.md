# atopile Project Template

This project can be used as a starting template for an atopile project. This template provides the following aspects:

- Simple examples of `ato` code located in the elec/src directory
- A kicad 7 project for pcb layout in the elec/layout directory
- A gitlab CI file to generate your artifacts automatically
- A gitignore file with the relevant files extensions to be ignored in the repository

## How to build

1. Install atopile following the documentation below
2. Run `ato build elec/src`
3. Load the netlist into your kicad pcb layout

## Documentation

The documentation for the project can be found at http://docs.atopile.io

## Example projects

The spin servo drive is an active project you can take inspiration from. Find it here: https://gitlab.atopile.io/atopile/servo-drive