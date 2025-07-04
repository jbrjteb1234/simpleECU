const sensorSections = [
  {
    section: 'Engine & Timing',
    sensors: [
      { id: 'rpm',       label: 'Revolutions Per Minute (RPM)' },
      { id: 'cmpPhase',  label: 'Camshaft Phase Offset'       },
      { id: 'knockLvl',  label: 'Knock Level'                 }
    ]
  }

  /*{
    section: 'Air-Flow'
  },

  {
    section: 'Charge Management'
  }*/
];

function buildSensors(sensorSections){

    const frag = document.createDocumentFragment();

    function produceSensor({id, label}){
        const row = document.createElement('div');
        row.className = 'sensor-row';

        const name = document.createElement('span');
        name.className = 'sensor-name';
        name.textContent = label;

        const reading = document.createElement('span');
        reading.className = 'sensor-reading';
        reading.id = id;
        reading.textContent = '--';

        row.append(name, reading);
        frag.appendChild(row);
    }

    function produceTitle({section, sensors = []}){

        const title = document.createElement('sensor-title');
        title.textContent = section;

        frag.appendChild(title);

        sensors.forEach(produceSensor);
    }

    sensorSections.forEach(produceTitle);

    return frag;
}

document
    .getElementById('output-sensor-flex-container')
    .appendChild(buildSensors(sensorSections));