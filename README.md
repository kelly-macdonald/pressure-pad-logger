# pressure-pad-logger
A pressure pad residing under a mat, used for logging uptime of a machine.

:Author: kelly-macdonald

:Email: kelly.macdonald@formlabs.com

:Date: 6/02/2022 

:Revision: 01 

Describe your project

## Step 1: Set Up Arduino IoT Cloud Account
Follow this [link](https://login.arduino.cc/login?state=hKFo2SBsWGpkdk1wbGtYUVFzUXU4emJMUTFkMFN0MjZUamc1Y6FupWxvZ2luo3RpZNkgekZUSk1rUXBOQ1AtNUd3TzVDdnR0SDFNQ1hRem5aT3WjY2lk2SB1bUJ5Ulk4SXBZTVZrUHF3QVQ5UHZraU4yYWtVTnlJUw&client=umByRY8IpYMVkPqwAT9PvkiN2akUNyIS&protocol=oauth2&authorizeTimeoutInSeconds=5&scope=openid+profile+email&redirect_uri=https%3A%2F%2Fcreate.arduino.cc%2Fiot%2F&skipAutoLogin=true&domain=login.arduino.cc&cacheLocation=memory&response_type=code&response_mode=query&nonce=akhGM2VyNnlrRUg0TlU3fi1xTzlrRGNDY2xQZUNPMGdJQVBRcmwwVFZ2dw%3D%3D&code_challenge=gC6LZ4tZvY8S-EQ9pU9STDL-DSJj1C0tIyfKZYu_sJY&code_challenge_method=S256&auth0Client=eyJuYW1lIjoiYXV0aDAtc3BhLWpzIiwidmVyc2lvbiI6IjEuMTIuMSJ9#/sso/register) to create a free account. Create a new "thing" and configure an Arduino MKR WiFi 1010 via a USB cable. Configure network connection with the desired network. Create two variables called person_on1 and person_on2 within the "thing". 

## Step 2: Upload code
In the sketch, paste the code from

## Step 3: Assemble circuit and mat

Assemble the circuit following the diagram pressure_mat_circuit.png found in this repository. Note that WiFi capability will be possible with an Arduino MKR WiFi 1010, although an Arduino UNO is depicted in the diagram.

## Step 4: Set up WebHook Applet via IFTTT

## Step 5: Process data in Google Sheets

### Folder structure

....
 sketch123                => Arduino sketch folder
  ├── sketch123.ino       => main Arduino file
  ├── schematics.png      => (optional) an image of the required schematics
  ├── layout.png          => (optional) an image of the layout
  └── ReadMe.adoc         => this file
....

## BOM

| Part name | Part number | Quantity
| 10k Resistor                      | CFR-25JR-52-10K | 6       
| LED                               | 2460-L513SRD-ND | 2        
| Force Sens Resistor               | 1027-1033-ND    | 6        
| Arduino MKR WiFi 1010             | 1050-1162-ND    | 1     
| Moisture-Resistant Polyester Film | 8567K12         | 1
