<?php
/**
 * @file
 * f24_rules_for_bid.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function f24_rules_for_bid_default_rules_configuration() {
  $items = array();
  $items['rules_link_condition_bid_award'] = entity_import('rules_config', '{ "rules_link_condition_bid_award" : {
      "LABEL" : "Rules link: Bid Award condition",
      "PLUGIN" : "and",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "node" : { "label" : "node", "type" : "node" },
        "node_carga" : { "label" : "node_carga", "type" : "node" }
      },
      "AND" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "node-carga" ],
            "type" : "node",
            "bundle" : { "value" : { "cargas" : "cargas" } }
          }
        },
        { "data_is" : {
            "data" : [ "node-carga:author:uid" ],
            "value" : [ "site:current-user:uid" ]
          }
        },
        { "NOT data_is" : {
            "data" : [ "node-carga:field-cargo-status" ],
            "op" : "IN",
            "value" : { "value" : {
                "CLOSE\\u00ad-AWARDED" : "CLOSE\\u00ad-AWARDED",
                "CLOSED-\\u00adNOT\\u00ad-AWARDED" : "CLOSED-\\u00adNOT\\u00ad-AWARDED"
              }
            }
          }
        }
      ]
    }
  }');
  $items['rules_link_set_bid_award'] = entity_import('rules_config', '{ "rules_link_set_bid_award" : {
      "LABEL" : "Rules link: Bid Award rules set",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "node" : { "type" : "node", "label" : "node" },
        "node_carga" : { "label" : "node_carga", "type" : "node" }
      },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "component_rules_link_condition_bid_award" : { "node" : [ "node" ], "node_carga" : [ "node_carga" ] } },
              { "node_is_of_type" : {
                  "node" : [ "node-carga" ],
                  "type" : { "value" : { "cargas" : "cargas" } }
                }
              }
            ],
            "DO" : [
              { "drupal_message" : { "message" : "Bid awarded" } },
              { "data_set" : {
                  "data" : [ "node-carga:field-cargo-status" ],
                  "value" : "CLOSE\\u00ad-AWARDED"
                }
              },
              { "data_set" : { "data" : [ "node-carga:field-bid-awarded" ], "value" : [ "node" ] } }
            ],
            "LABEL" : "Award Bid Link Reaction"
          }
        }
      ]
    }
  }');
  $items['rules_schedule_carga_expiration_action'] = entity_import('rules_config', '{ "rules_schedule_carga_expiration_action" : {
      "LABEL" : "Schedule: Carga expiration action",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "cargas" : "cargas" } } } },
        { "NOT data_is" : {
            "data" : [ "node:field-cargo-status" ],
            "value" : "CLOSE\\u00ad-AWARDED"
          }
        }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "node:field-cargo-status" ],
            "value" : "CLOSED-\\u00adNOT\\u00ad-AWARDED"
          }
        }
      ]
    }
  }');
  $items['rules_schedule_set_carga_expiration'] = entity_import('rules_config', '{ "rules_schedule_set_carga_expiration" : {
      "LABEL" : "Schedule: Set Carga expiration",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_scheduler" ],
      "ON" : {
        "node_insert--cargas" : { "bundle" : "cargas" },
        "node_update--cargas" : { "bundle" : "cargas" }
      },
      "DO" : [
        { "schedule" : {
            "component" : "rules_schedule_carga_expiration_action",
            "date" : [ "node:field-cargo-available:value2" ],
            "identifier" : "carga_expiration_[node:nid]",
            "param_node" : [ "node" ]
          }
        }
      ]
    }
  }');
  return $items;
}
