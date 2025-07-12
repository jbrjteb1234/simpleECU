const sensorSections = [
  {
    section: 'Engine & Timing',
    sensors: [
      { id: 'rpm',       label: 'Revolutions Per Minute (RPM)'},
      { id: 'cmpPhase',  label: 'Camshaft Phase Offset',      metric: '*'},
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

    function produceSensor({id, label, metric=''}){
        const row = document.createElement('div');
        row.className = 'sensor-output-row';

        const name = document.createElement('span');
        name.className = 'sensor-name';
        name.textContent = label;

        const reading = document.createElement('span');
        reading.className = 'sensor-reading';
        reading.id = id;
        reading.textContent = '--';

        const metricElement = document.createElement('span');
        metricElement.className = 'sensor-metric';
        metricElement.textContent = metric;

        row.append(name, reading, metricElement);
        frag.appendChild(row);
    }

    function produceTitle({section, sensors = []}){

        const title = document.createElement('h3');
        title.className = 'sensor-title';
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