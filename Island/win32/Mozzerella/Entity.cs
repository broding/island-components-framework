using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml.Linq;

namespace Mozzerella
{
    class Entity
    {
        public uint id { get; private set; }
        public string name { get; set; }

        private List<XElement> componentsXML;

        public Entity(XDocument document)
        {
            id = uint.Parse(document.Element("entity").Attribute("id").Value);
            name = document.Element("entity").Attribute("name").Value;
            
            componentsXML = document.Element("entity").Element("components").Elements().ToList<XElement>();
        }

        public List<string> GetComponentList()
        {
            List<string> components = new List<string>();

            foreach (XElement element in componentsXML)
                components.Add(element.Attribute("name").Value);

            return components;
        }

        public Dictionary<string, object> GetComponentsData(int componentIndex)
        {
            Dictionary<string, object> data = new Dictionary<string, object>();

            foreach (XElement element in componentsXML[componentIndex].Elements("data"))
                data.Add(element.Attribute("type").Value, element.Attribute("value").Value);

            return data;
        }

        public void UpdateComponentData(int componentIndex, string key, string value)
        {
            foreach (XElement element in componentsXML[componentIndex].Elements("data"))
            {
                if (element.Attribute("type").Value == key)
                {
                    element.Attribute("value").Value = value;
                    return;
                }
            }
        }

        public XDocument CreateXML()
        {
            XDocument document = new XDocument();
            XElement entity = new XElement("entity",

                    new XAttribute("name", this.name),
                    new XAttribute("id", this.id)
            );

            XElement components = new XElement("components");

            foreach (XElement element in this.componentsXML)
                components.Add(element);

            entity.Add(components);
            document.Add(entity);

            return document;
        }
    }
}
