/*
 Navicat Premium Data Transfer

 Source Server         : MySQL-localhost
 Source Server Type    : MySQL
 Source Server Version : 80030 (8.0.30)
 Source Host           : localhost:3306
 Source Schema         : flightmanagement

 Target Server Type    : MySQL
 Target Server Version : 80030 (8.0.30)
 File Encoding         : 65001

 Date: 04/11/2022 17:58:29
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for flightinfo
-- ----------------------------
DROP TABLE IF EXISTS `flightinfo`;
CREATE TABLE `flightinfo`  (
  `flight_id` varchar(64) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `from_airport` varchar(32) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `dst_airport` varchar(32) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `monday` bit(1) NOT NULL DEFAULT b'0',
  `tuesday` bit(1) NOT NULL DEFAULT b'0',
  `wednesday` bit(1) NOT NULL DEFAULT b'0',
  `thursday` bit(1) NOT NULL DEFAULT b'0',
  `friday` bit(1) NOT NULL DEFAULT b'0',
  `saturday` bit(1) NOT NULL DEFAULT b'0',
  `sunday` bit(1) NOT NULL DEFAULT b'0',
  `departure_time` time NULL DEFAULT NULL,
  `arrival_time` time NULL DEFAULT NULL,
  `economy_seats` int UNSIGNED NULL DEFAULT 0,
  `business_seats` int UNSIGNED NULL DEFAULT NULL,
  `first_seats` int UNSIGNED NULL DEFAULT NULL,
  `economy_price` decimal(10, 2) NULL DEFAULT NULL,
  `business_price` decimal(10, 2) NULL DEFAULT NULL,
  `first_price` decimal(10, 2) NULL DEFAULT NULL,
  `status` int UNSIGNED NULL DEFAULT NULL,
  `type` int NULL DEFAULT NULL,
  `aircraft` int UNSIGNED NULL DEFAULT NULL,
  PRIMARY KEY (`flight_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = Dynamic;

SET FOREIGN_KEY_CHECKS = 1;
