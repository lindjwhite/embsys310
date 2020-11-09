I recently received a [Casper Glow Light](https://casper.com/glow-light/) to help with waking up before the sun, so I thought it would be an interesting embedded device to pick apart.

The light receives both physical data in the form of movement and data over a bluetooth link on your phone in order to perform specific tasks like lighting up when flipped, changing brightness of light by rotating device and gradually increasing light as a simulated sunrise. For movement tracking, the unit probably uses some form of gyroscope, and for bluetooth, a bluetooth module. I would assume the device uses some form of specialized LED driver, since the transitions and colors are smooth and nuanced. A break down of the flow for the system would look like:

Bluetooth or Physical Input --> Glow Internal Processor --> Change in lighting

The development challenges I would foresee would be:
1. Response time - the light needs to transition smoothly, from soft to bright or vice versa, given rotational input from the user.
2. Testability/Debugability - the only output produced by the system is done by change in light, and there is only so much testing and debugging that can be done by monitoring light changes.
3. Reliability - it would be really unfortunate if your alarm didn't go off when it's supposed to.
4. Security - having someone else able to access the light would be a challenge, as they could change your settings or turn the light on at an inopportune time (like in the middle of the night).
