# Design File
### Animesh Jha  19CS10070 ###
NOTE: In my solution I have used  `BookingClass` instead of `BookingClasses` please note the slight difference in naming while evaluating.

# High Level Design (HLD)
## Design Principles ##
The following design principles were adhered to in HLD:
1. Flexible & Extensible Design
    1. The design should be flexible. It should be easy to change the changeable parameters (like
        base rate, load factor etc.) easily from the application space. This should not need re-building
        of the library of classes.
    2. The design should be extensible. It should be easy to add new classes anywhere. Should not
        require a re-coding.
2. Minimal Design
    1. Used type deduction `auto` wherever possible to improve readability
    2. Only the stated models and behaviour should be coded. No extra class or method should be coded.
    3. Less code, less error principle to be followed.
3. Reliable Design
    1. Reliability should be a priority. Everything should work as designed and coded.
    2. Data members, methods and objects should be made constant wherever possible.
    3. Parameters should be appropriately defaulted wherever possible
4. Testable Design
    1. Every class should support the output streaming operator for checking intermittent output if needed.
    2. Every class should be unit tested.
    3. Test Applications should be designed for testing the application on different scenarios of use.
##  Classes ##
