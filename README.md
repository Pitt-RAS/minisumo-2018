# minisumo-2018
Code for Mini Sumo competition, IEEE SAC Region 2 2018

## Dependencies
1. libsumobot: it's in this repo
## TODO
- [ ] Re-wire the motor driver in a more concise way
- [x] Create functional process to control motor drive and breaking
  - [x] Get the motors to stop spinning when we want them to
  - [x] Figure out what short braking is
    - [x] Implement short braking
- [ ] Implement encoder library to derive speed from motors during operation
- [ ] Implement logic for ring boundaries; i.e. when we reach the end of the 
circle, reverse
- [ ] Implement offensive strategies
- [ ] Implement logic for edge-case scenarios; i.e. the robot gets stuck, our 
attack is ineffective
