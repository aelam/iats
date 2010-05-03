/*
 * Copyright(c) 2007 Atheros Corporation. All rights reserved.
 *
 * Derived from Intel e1000 driver
 * Copyright(c) 1999 - 2005 Intel Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59
 * Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * There are a lot of defines in here that are unused and/or have cryptic
 * names.  Please leave them alone, as they're the closest thing we have
 * to a spec from Atheros at present. *ahem* -- CHS
 */

#ifndef _ATHEROS_HW_H__
#define _ATHEROS_HW_H__

#include "at_osdep.h"

#define _AT_ATTRIB_PACK_    __attribute__ ((packed))

struct at_adapter;
struct at_hw;

/* function prototype */

s32 at_reset_hw(struct at_hw* hw);
s32 at_read_mac_addr(struct at_hw* hw);
s32 at_init_hw(struct at_hw* hw);
s32 at_phy_setup_autoneg_adv(struct at_hw *hw);
s32 at_phy_commit(struct at_hw *hw);
s32 at_get_speed_and_duplex(struct at_hw *hw, u16 *speed, u16 *duplex);
u32 at_auto_get_fc(struct at_adapter* adapter, u16 duplex);
u32 at_hash_mc_addr(struct at_hw *hw, u8 *mc_addr);
void at_hash_set(struct at_hw *hw, u32 hash_value);
s32 at_read_phy_reg(struct at_hw *hw, u16 reg_addr, u16 *phy_data);
s32 at_write_phy_reg(struct at_hw *hw, u32 reg_addr, u16 phy_data);
void at_read_pci_cfg(struct at_hw*  hw, u32 reg, u16 *value);
void at_write_pci_cfg(struct at_hw* hw, u32 reg, u16 *value); 
s32 at_validate_mdi_setting(struct at_hw* hw);
void set_mac_addr(struct at_hw* hw);
int get_permanent_address(struct at_hw* hw);
boolean_t read_eeprom(struct at_hw* hw, u32 Offset, u32* pValue);
boolean_t write_eeprom(struct at_hw* hw, u32 offset, u32 value);
s32 at_phy_init(struct at_hw* hw);
int check_eeprom_exist(struct at_hw* hw);
void init_flash_opcode(struct at_hw* hw);
boolean_t spi_read(struct at_hw* hw, uint32_t addr, uint32_t* buf);
boolean_t check_cable(struct at_hw *hw);
void at_force_ps(struct at_hw* hw);

/* register definition */
#define REG_PM_CTRLSTAT             0x44

#define REG_PCIE_CAP_LIST           0x58

#define REG_DEVICE_CAP              0x5C
#define     DEVICE_CAP_MAX_PAYLOAD_MASK     0x7
#define     DEVICE_CAP_MAX_PAYLOAD_SHIFT    0

#define REG_DEVICE_CTRL             0x60
#define     DEVICE_CTRL_MAX_PAYLOAD_MASK    0x7
#define     DEVICE_CTRL_MAX_PAYLOAD_SHIFT   5
#define     DEVICE_CTRL_MAX_RREQ_SZ_MASK    0x7
#define     DEVICE_CTRL_MAX_RREQ_SZ_SHIFT   12

#define REG_VPD_CAP                 0x6C
#define     VPD_CAP_ID_MASK                 0xff
#define     VPD_CAP_ID_SHIFT                0
#define     VPD_CAP_NEXT_PTR_MASK           0xFF
#define     VPD_CAP_NEXT_PTR_SHIFT          8
#define     VPD_CAP_VPD_ADDR_MASK           0x7FFF
#define     VPD_CAP_VPD_ADDR_SHIFT          16
#define     VPD_CAP_VPD_FLAG                0x80000000

#define REG_VPD_DATA                0x70

#define REG_SPI_FLASH_CTRL          0x200
#define     SPI_FLASH_CTRL_STS_NON_RDY      0x1
#define     SPI_FLASH_CTRL_STS_WEN          0x2
#define     SPI_FLASH_CTRL_STS_WPEN         0x80
#define     SPI_FLASH_CTRL_DEV_STS_MASK     0xFF
#define     SPI_FLASH_CTRL_DEV_STS_SHIFT    0
#define     SPI_FLASH_CTRL_INS_MASK         0x7
#define     SPI_FLASH_CTRL_INS_SHIFT        8
#define     SPI_FLASH_CTRL_START            0x800
#define     SPI_FLASH_CTRL_EN_VPD           0x2000
#define     SPI_FLASH_CTRL_LDSTART          0x8000
#define     SPI_FLASH_CTRL_CS_HI_MASK       0x3
#define     SPI_FLASH_CTRL_CS_HI_SHIFT      16
#define     SPI_FLASH_CTRL_CS_HOLD_MASK     0x3
#define     SPI_FLASH_CTRL_CS_HOLD_SHIFT    18
#define     SPI_FLASH_CTRL_CLK_LO_MASK      0x3
#define     SPI_FLASH_CTRL_CLK_LO_SHIFT     20
#define     SPI_FLASH_CTRL_CLK_HI_MASK      0x3
#define     SPI_FLASH_CTRL_CLK_HI_SHIFT     22
#define     SPI_FLASH_CTRL_CS_SETUP_MASK    0x3
#define     SPI_FLASH_CTRL_CS_SETUP_SHIFT   24
#define     SPI_FLASH_CTRL_EROM_PGSZ_MASK   0x3
#define     SPI_FLASH_CTRL_EROM_PGSZ_SHIFT  26
#define     SPI_FLASH_CTRL_WAIT_READY       0x10000000

#define REG_SPI_ADDR                0x204

#define REG_SPI_DATA                0x208

#define REG_SPI_FLASH_CONFIG        0x20C
#define     SPI_FLASH_CONFIG_LD_ADDR_MASK   0xFFFFFF
#define     SPI_FLASH_CONFIG_LD_ADDR_SHIFT  0
#define     SPI_FLASH_CONFIG_VPD_ADDR_MASK  0x3
#define     SPI_FLASH_CONFIG_VPD_ADDR_SHIFT 24
#define     SPI_FLASH_CONFIG_LD_EXIST       0x4000000


#define REG_SPI_FLASH_OP_PROGRAM    0x210
#define REG_SPI_FLASH_OP_SC_ERASE   0x211
#define REG_SPI_FLASH_OP_CHIP_ERASE 0x212
#define REG_SPI_FLASH_OP_RDID       0x213
#define REG_SPI_FLASH_OP_WREN       0x214
#define REG_SPI_FLASH_OP_RDSR       0x215
#define REG_SPI_FLASH_OP_WRSR       0x216
#define REG_SPI_FLASH_OP_READ       0x217

#define REG_TWSI_CTRL               0x218
#define     TWSI_CTRL_LD_OFFSET_MASK        0xFF
#define     TWSI_CTRL_LD_OFFSET_SHIFT       0
#define     TWSI_CTRL_LD_SLV_ADDR_MASK      0x7
#define     TWSI_CTRL_LD_SLV_ADDR_SHIFT     8
#define     TWSI_CTRL_SW_LDSTART            0x800
#define     TWSI_CTRL_HW_LDSTART            0x1000
#define     TWSI_CTRL_SMB_SLV_ADDR_MASK     0x7F
#define     TWSI_CTRL_SMB_SLV_ADDR_SHIFT    15
#define     TWSI_CTRL_LD_EXIST              0x400000
#define     TWSI_CTRL_READ_FREQ_SEL_MASK    0x3
#define     TWSI_CTRL_READ_FREQ_SEL_SHIFT   23
#define     TWSI_CTRL_FREQ_SEL_100K         0
#define     TWSI_CTRL_FREQ_SEL_200K         1
#define     TWSI_CTRL_FREQ_SEL_300K         2
#define     TWSI_CTRL_FREQ_SEL_400K         3
#define     TWSI_CTRL_SMB_SLV_ADDR
#define     TWSI_CTRL_WRITE_FREQ_SEL_MASK   0x3
#define     TWSI_CTRL_WRITE_FREQ_SEL_SHIFT  24


#define REG_PCIE_DEV_MISC_CTRL      0x21C
#define     PCIE_DEV_MISC_CTRL_EXT_PIPE     0x2
#define     PCIE_DEV_MISC_CTRL_RETRY_BUFDIS 0x1
#define     PCIE_DEV_MISC_CTRL_SPIROM_EXIST 0x4
#define     PCIE_DEV_MISC_CTRL_SERDES_ENDIAN    0x8
#define     PCIE_DEV_MISC_CTRL_SERDES_SEL_DIN   0x10

#define REG_PCIE_PHYMISC            0x1000
#define     PCIE_PHYMISC_FORCE_RCV_DET      0x4

#define REG_LTSSM_TEST_MODE         0x12FC
#define     LTSSM_TEST_MODE_DEF             0x6500

// Selene Master Control Register
#define REG_MASTER_CTRL             0x1400
#define     MASTER_CTRL_SOFT_RST            0x1    
#define     MASTER_CTRL_MTIMER_EN           0x2 
#define     MASTER_CTRL_ITIMER_EN           0x4
#define     MASTER_CTRL_MANUAL_INT          0x8 
#define     MASTER_CTRL_REV_NUM_SHIFT       16     
#define     MASTER_CTRL_REV_NUM_MASK        0xff
#define     MASTER_CTRL_DEV_ID_SHIFT        24    
#define     MASTER_CTRL_DEV_ID_MASK         0xff

// Timer Initial Value Register
#define REG_MANUAL_TIMER_INIT       0x1404

// IRQ ModeratorTimer Initial Value Register
#define REG_IRQ_MODU_TIMER_INIT     0x1408      

#define REG_GPHY_ENABLE         0x140C //w
// IRQ Anti-Lost Timer Initial Value Register
#define REG_CMBDISDMA_TIMER         0x140E      
// Block IDLE Status Register
#define REG_IDLE_STATUS             0x1410
#define     IDLE_STATUS_RXMAC               1  
#define     IDLE_STATUS_TXMAC               2 
#define     IDLE_STATUS_RXQ                 4  
#define     IDLE_STATUS_TXQ                 8 
#define     IDLE_STATUS_DMAR                0x10       
#define     IDLE_STATUS_DMAW                0x20      
#define     IDLE_STATUS_SMB                 0x40     
#define     IDLE_STATUS_CMB                 0x80    

// MDIO Control Register
#define REG_MDIO_CTRL               0x1414
#define     MDIO_DATA_MASK                  0xffff 
#define     MDIO_DATA_SHIFT                 0     
#define     MDIO_REG_ADDR_MASK              0x1f 
#define     MDIO_REG_ADDR_SHIFT             16
#define     MDIO_RW                         0x200000     
#define     MDIO_SUP_PREAMBLE               0x400000   
#define     MDIO_START                      0x800000   
#define     MDIO_CLK_SEL_SHIFT              24
#define     MDIO_CLK_25_4                   0
#define     MDIO_CLK_25_6                   2
#define     MDIO_CLK_25_8                   3
#define     MDIO_CLK_25_10                  4
#define     MDIO_CLK_25_14                  5
#define     MDIO_CLK_25_20                  6
#define     MDIO_CLK_25_28                  7
#define     MDIO_BUSY                       0x8000000       
#define     MDIO_WAIT_TIMES                 30        

// MII PHY Status Register
#define REG_PHY_STATUS              0x1418                   

// BIST Control and Status Register0 (for the Packet Memory)
#define REG_BIST0_CTRL              0x141c                   
#define     BIST0_NOW                       0x1       
#define     BIST0_SRAM_FAIL                 0x2    
#define     BIST0_FUSE_FLAG                 0x4  
#define REG_BIST1_CTRL              0x1420                   
#define     BIST1_NOW                       0x1        
#define     BIST1_SRAM_FAIL                 0x2        
#define     BIST1_FUSE_FLAG                 0x4

#define REG_SERDES_LOCK             0x1424
#define     SERDES_LOCK_DETECT              1
#define     SERDES_LOCK_DETECT_EN           2


// MAC Control Register                         
#define REG_MAC_CTRL                0x1480                  
#define     MAC_CTRL_TX_EN                  1   
#define     MAC_CTRL_RX_EN                  2    
#define     MAC_CTRL_TX_FLOW                4     
#define     MAC_CTRL_RX_FLOW                8      
#define     MAC_CTRL_LOOPBACK               0x10    
#define     MAC_CTRL_DUPLX                  0x20     
#define     MAC_CTRL_ADD_CRC                0x40       
#define     MAC_CTRL_PAD                    0x80      
#define     MAC_CTRL_LENCHK                 0x100       
#define     MAC_CTRL_HUGE_EN                0x200        
#define     MAC_CTRL_PRMLEN_SHIFT           10            
#define     MAC_CTRL_PRMLEN_MASK            0xf                 
#define     MAC_CTRL_RMV_VLAN               0x4000        
#define     MAC_CTRL_PROMIS_EN              0x8000       
#define     MAC_CTRL_TX_PAUSE               0x10000    
#define     MAC_CTRL_SCNT                   0x20000   
#define     MAC_CTRL_SRST_TX                0x40000        
#define     MAC_CTRL_TX_SIMURST             0x80000       
#define     MAC_CTRL_SPEED_SHIFT            20           
#define     MAC_CTRL_SPEED_MASK             0x300000
#define     MAC_CTRL_SPEED_1000             2
#define     MAC_CTRL_SPEED_10_100           1
#define     MAC_CTRL_DBG_TX_BKPRESURE       0x400000    
#define     MAC_CTRL_TX_HUGE                0x800000   
#define     MAC_CTRL_RX_CHKSUM_EN           0x1000000 
#define     MAC_CTRL_MC_ALL_EN              0x2000000           
#define     MAC_CTRL_BC_EN                  0x4000000      
#define     MAC_CTRL_DBG                    0x8000000     

// MAC IPG/IFG Control Register                 
#define REG_MAC_IPG_IFG             0x1484                   
#define     MAC_IPG_IFG_IPGT_SHIFT          0            
#define     MAC_IPG_IFG_IPGT_MASK           0x7f
#define     MAC_IPG_IFG_MIFG_SHIFT          8           
#define     MAC_IPG_IFG_MIFG_MASK           0xff       
#define     MAC_IPG_IFG_IPGR1_SHIFT         16        
#define     MAC_IPG_IFG_IPGR1_MASK          0x7f     
#define     MAC_IPG_IFG_IPGR2_SHIFT         24      
#define     MAC_IPG_IFG_IPGR2_MASK          0x7f

// MAC STATION ADDRESS                          
#define REG_MAC_STA_ADDR            0x1488

// Hash table for multicast address
#define REG_RX_HASH_TABLE           0x1490

// MAC Half-Duplex Control Register 
#define REG_MAC_HALF_DUPLX_CTRL     0x1498                   
#define     MAC_HALF_DUPLX_CTRL_LCOL_SHIFT   0     
#define     MAC_HALF_DUPLX_CTRL_LCOL_MASK    0x3ff
#define     MAC_HALF_DUPLX_CTRL_RETRY_SHIFT  12   
#define     MAC_HALF_DUPLX_CTRL_RETRY_MASK   0xf
#define     MAC_HALF_DUPLX_CTRL_EXC_DEF_EN   0x10000         
#define     MAC_HALF_DUPLX_CTRL_NO_BACK_C    0x20000   
#define     MAC_HALF_DUPLX_CTRL_NO_BACK_P    0x40000       
#define     MAC_HALF_DUPLX_CTRL_ABEBE        0x80000      
#define     MAC_HALF_DUPLX_CTRL_ABEBT_SHIFT  20          
#define     MAC_HALF_DUPLX_CTRL_ABEBT_MASK   0xf
#define     MAC_HALF_DUPLX_CTRL_JAMIPG_SHIFT 24          
#define     MAC_HALF_DUPLX_CTRL_JAMIPG_MASK  0xf       

// Maximum Frame Length Control Register   
#define REG_MTU                     0x149c                   

// Wake-On-Lan control register
#define REG_WOL_CTRL                0x14a0                   
#define     WOL_PATTERN_EN                  0x00000001
#define     WOL_PATTERN_PME_EN              0x00000002
#define     WOL_MAGIC_EN                    0x00000004
#define     WOL_MAGIC_PME_EN                0x00000008
#define     WOL_LINK_CHG_EN                 0x00000010
#define     WOL_LINK_CHG_PME_EN             0x00000020
#define     WOL_PATTERN_ST                  0x00000100
#define     WOL_MAGIC_ST                    0x00000200
#define     WOL_LINKCHG_ST                  0x00000400
#define     WOL_CLK_SWITCH_EN               0x00008000
#define     WOL_PT0_EN                      0x00010000
#define     WOL_PT1_EN                      0x00020000
#define     WOL_PT2_EN                      0x00040000
#define     WOL_PT3_EN                      0x00080000
#define     WOL_PT4_EN                      0x00100000
#define     WOL_PT5_EN                      0x00200000
#define     WOL_PT6_EN                      0x00400000

// WOL Length ( 2 DWORD )
#define REG_WOL_PATTERN_LEN         0x14a4
#define     WOL_PT_LEN_MASK                 0x7f
#define     WOL_PT0_LEN_SHIFT               0
#define     WOL_PT1_LEN_SHIFT               8
#define     WOL_PT2_LEN_SHIFT               16
#define     WOL_PT3_LEN_SHIFT               24
#define     WOL_PT4_LEN_SHIFT               0
#define     WOL_PT5_LEN_SHIFT               8
#define     WOL_PT6_LEN_SHIFT               16

// Internal SRAM Partition Register 
#define REG_SRAM_RFD_ADDR           0x1500                           
#define REG_SRAM_RFD_LEN            (REG_SRAM_RFD_ADDR+ 4)    
#define REG_SRAM_RRD_ADDR           (REG_SRAM_RFD_ADDR+ 8)     
#define REG_SRAM_RRD_LEN            (REG_SRAM_RFD_ADDR+12)         
#define REG_SRAM_TPD_ADDR           (REG_SRAM_RFD_ADDR+16)  
#define REG_SRAM_TPD_LEN            (REG_SRAM_RFD_ADDR+20)        
#define REG_SRAM_TRD_ADDR           (REG_SRAM_RFD_ADDR+24)       
#define REG_SRAM_TRD_LEN            (REG_SRAM_RFD_ADDR+28)  
#define REG_SRAM_RXF_ADDR           (REG_SRAM_RFD_ADDR+32)           
#define REG_SRAM_RXF_LEN            (REG_SRAM_RFD_ADDR+36)           
#define REG_SRAM_TXF_ADDR           (REG_SRAM_RFD_ADDR+40)             
#define REG_SRAM_TXF_LEN            (REG_SRAM_RFD_ADDR+44)              
#define REG_SRAM_TCPH_PATH_ADDR     (REG_SRAM_RFD_ADDR+48)
#define     SRAM_TCPH_ADDR_MASK             0x0fff              
#define     SRAM_TCPH_ADDR_SHIFT            0
#define     SRAM_PATH_ADDR_MASK             0x0fff
#define     SRAM_PATH_ADDR_SHIFT            16

// Load Ptr Register 
#define REG_LOAD_PTR                (REG_SRAM_RFD_ADDR+52)    

//  Descriptor Control register                                     
#define REG_DESC_BASE_ADDR_HI       0x1540         
#define REG_DESC_RFD_ADDR_LO        (REG_DESC_BASE_ADDR_HI+4)   
#define REG_DESC_RRD_ADDR_LO        (REG_DESC_BASE_ADDR_HI+8)    
#define REG_DESC_TPD_ADDR_LO        (REG_DESC_BASE_ADDR_HI+12)       
#define REG_DESC_CMB_ADDR_LO        (REG_DESC_BASE_ADDR_HI+16)              
#define REG_DESC_SMB_ADDR_LO        (REG_DESC_BASE_ADDR_HI+20)              
#define REG_DESC_RFD_RRD_RING_SIZE  (REG_DESC_BASE_ADDR_HI+24)          
#define     DESC_RFD_RING_SIZE_MASK         0x7ff
#define     DESC_RFD_RING_SIZE_SHIFT        0
#define     DESC_RRD_RING_SIZE_MASK         0x7ff
#define     DESC_RRD_RING_SIZE_SHIFT        16
#define REG_DESC_TPD_RING_SIZE      (REG_DESC_BASE_ADDR_HI+28)      
#define     DESC_TPD_RING_SIZE_MASK         0x3ff
#define     DESC_TPD_RING_SIZE_SHIFT        0                       

// TXQ Control Register                                                                                                                    
#define REG_TXQ_CTRL                0x1580       
#define     TXQ_CTRL_TPD_BURST_NUM_SHIFT    0                  
#define     TXQ_CTRL_TPD_BURST_NUM_MASK     0x1f
#define     TXQ_CTRL_EN                     0x20          
#define     TXQ_CTRL_ENH_MODE               0x40                
#define     TXQ_CTRL_TPD_FETCH_TH_SHIFT     8                    
#define     TXQ_CTRL_TPD_FETCH_TH_MASK      0x3f
#define     TXQ_CTRL_TXF_BURST_NUM_SHIFT    16                 
#define     TXQ_CTRL_TXF_BURST_NUM_MASK     0xffff  

// Jumbo packet Threshold for task offload
#define REG_TX_JUMBO_TASK_TH_TPD_IPG        0x1584              
#define     TX_JUMBO_TASK_TH_MASK           0x7ff
#define     TX_JUMBO_TASK_TH_SHIFT          0
#define     TX_TPD_MIN_IPG_MASK             0x1f
#define     TX_TPD_MIN_IPG_SHIFT            16


// RXQ Control Register
#define REG_RXQ_CTRL                0x15a0    
#define     RXQ_CTRL_RFD_BURST_NUM_SHIFT    0                      
#define     RXQ_CTRL_RFD_BURST_NUM_MASK     0xff                
#define     RXQ_CTRL_RRD_BURST_THRESH_SHIFT 8                      
#define     RXQ_CTRL_RRD_BURST_THRESH_MASK  0xff                
#define     RXQ_CTRL_RFD_PREF_MIN_IPG_SHIFT 16
#define     RXQ_CTRL_RFD_PREF_MIN_IPG_MASK  0x1f
#define     RXQ_CTRL_CUT_THRU_EN            0x40000000
#define     RXQ_CTRL_EN                     0x80000000             

// Rx jumbo packet threshold and rrd  retirement timer         
#define REG_RXQ_JMBOSZ_RRDTIM       (REG_RXQ_CTRL+ 4)           
#define     RXQ_JMBOSZ_TH_MASK              0x7ff              
#define     RXQ_JMBOSZ_TH_SHIFT             0           
#define     RXQ_JMBO_LKAH_MASK              0xf
#define     RXQ_JMBO_LKAH_SHIFT             11
#define     RXQ_RRD_TIMER_MASK              0xffff
#define     RXQ_RRD_TIMER_SHIFT             16

// RFD flow control register
#define REG_RXQ_RXF_PAUSE_THRESH    (REG_RXQ_CTRL+ 8)       
#define     RXQ_RXF_PAUSE_TH_HI_SHIFT       16
#define     RXQ_RXF_PAUSE_TH_HI_MASK        0xfff
#define     RXQ_RXF_PAUSE_TH_LO_SHIFT       0  
#define     RXQ_RXF_PAUSE_TH_LO_MASK        0xfff   

// RRD flow control register
#define REG_RXQ_RRD_PAUSE_THRESH    (REG_RXQ_CTRL+12)       
#define     RXQ_RRD_PAUSE_TH_HI_SHIFT       0
#define     RXQ_RRD_PAUSE_TH_HI_MASK        0xfff
#define     RXQ_RRD_PAUSE_TH_LO_SHIFT       16
#define     RXQ_RRD_PAUSE_TH_LO_MASK        0xfff

// DMA Engine Control Register
#define REG_DMA_CTRL                0x15c0                   
#define     DMA_CTRL_DMAR_IN_ORDER          0x1
#define     DMA_CTRL_DMAR_ENH_ORDER         0x2
#define     DMA_CTRL_DMAR_OUT_ORDER         0x4
#define     DMA_CTRL_RCB_VALUE              0x8
#define     DMA_CTRL_DMAR_BURST_LEN_SHIFT   4
#define     DMA_CTRL_DMAR_BURST_LEN_MASK    7
#define     DMA_CTRL_DMAW_BURST_LEN_SHIFT   7
#define     DMA_CTRL_DMAW_BURST_LEN_MASK    7
#define     DMA_CTRL_DMAR_EN                0x400
#define     DMA_CTRL_DMAW_EN                0x800

// CMB/SMB Control Register
#define REG_CSMB_CTRL               0x15d0
#define     CSMB_CTRL_CMB_NOW               1                 
#define     CSMB_CTRL_SMB_NOW               2                 
#define     CSMB_CTRL_CMB_EN                4                
#define     CSMB_CTRL_SMB_EN                8                  

// CMB DMA Write Threshold Register
#define REG_CMB_WRITE_TH            (REG_CSMB_CTRL+ 4)          
#define     CMB_RRD_TH_SHIFT                0                  
#define     CMB_RRD_TH_MASK                 0x7ff
#define     CMB_TPD_TH_SHIFT                16                 
#define     CMB_TPD_TH_MASK                 0x7ff

// RX/TX count-down timer to trigger CMB-write. 2us resolution.
#define REG_CMB_WRITE_TIMER         (REG_CSMB_CTRL+ 8) 
#define     CMB_RX_TM_SHIFT                 0                   
#define     CMB_RX_TM_MASK                  0xffff
#define     CMB_TX_TM_SHIFT                 16                
#define     CMB_TX_TM_MASK                  0xffff                  

// Number of packet received since last CMB write     
#define REG_CMB_RX_PKT_CNT          (REG_CSMB_CTRL+12)      

// Number of packet transmitted since last CMB write
#define REG_CMB_TX_PKT_CNT          (REG_CSMB_CTRL+16)      

// SMB auto DMA timer register
#define REG_SMB_TIMER               (REG_CSMB_CTRL+20)          

// Mailbox Register
#define REG_MAILBOX                 0x15f0
#define     MB_RFD_PROD_INDX_SHIFT          0                
#define     MB_RFD_PROD_INDX_MASK           0x7ff
#define     MB_RRD_CONS_INDX_SHIFT          11                  
#define     MB_RRD_CONS_INDX_MASK           0x7ff
#define     MB_TPD_PROD_INDX_SHIFT          22                 
#define     MB_TPD_PROD_INDX_MASK           0x3ff

// Interrupt Status Register
#define REG_ISR                     0x1600                   
#define     ISR_SMB                         1                   
#define     ISR_TIMER                       2                  
#define     ISR_MANUAL                      4                
#define     ISR_RXF_OV                      8                  
#define     ISR_RFD_UNRUN                   0x10              
#define     ISR_RRD_OV                      0x20           
#define     ISR_TXF_UNRUN                   0x40          
#define     ISR_LINK                        0x80        
#define     ISR_HOST_RFD_UNRUN              0x100
#define     ISR_HOST_RRD_OV                 0x200
#define     ISR_DMAR_TO_RST                 0x400
#define     ISR_DMAW_TO_RST                 0x800
#define     ISR_GPHY                        0x1000
#define     ISR_RX_PKT                      0x10000   
#define     ISR_TX_PKT                      0x20000  
#define     ISR_TX_DMA                      0x40000 
#define     ISR_RX_DMA                      0x80000
#define     ISR_CMB_RX                      0x100000
#define     ISR_CMB_TX                      0x200000
#define     ISR_MAC_RX                      0x400000
#define     ISR_MAC_TX                      0x800000
#define     ISR_UR_DETECTED                 0x1000000
#define     ISR_FERR_DETECTED               0x2000000
#define     ISR_NFERR_DETECTED              0x4000000
#define     ISR_CERR_DETECTED               0x8000000
#define     ISR_PHY_LINKDOWN                0x10000000
#define     ISR_DIS_SMB                     0x20000000
#define     ISR_DIS_DMA                     0x40000000
#define     ISR_DIS_INT                     0x80000000

// Interrupt Mask Register
#define REG_IMR                     0x1604             


/* Normal Interrupt mask  */
#define IMR_NORMAL_MASK     (\
ISR_MANUAL      |        \
ISR_SMB         |        \
ISR_GPHY        |        \
ISR_PHY_LINKDOWN|        \
ISR_DMAR_TO_RST |        \
ISR_DMAW_TO_RST |        \
ISR_CMB_TX      |        \
ISR_CMB_RX      ) 

/* Normal Non-Rx Interrupt mask  */
#define IMR_NONRX_MASK     (\
ISR_MANUAL      |        \
ISR_SMB         |        \
ISR_GPHY        |        \
ISR_PHY_LINKDOWN|        \
ISR_DMAR_TO_RST |        \
ISR_DMAW_TO_RST |        \
ISR_CMB_TX      ) 

#define ISR_TX_EVENT        (\
ISR_TXF_UNRUN           |\
ISR_TX_PKT              |\
ISR_TX_DMA              |\
ISR_CMB_TX              |\
ISR_MAC_TX              )

#define ISR_RX_EVENT        (\
ISR_RXF_OV              |\
ISR_RFD_UNRUN           |\
ISR_RRD_OV              |\
ISR_HOST_RFD_UNRUN      |\
ISR_HOST_RRD_OV         |\
ISR_RX_PKT              |\
ISR_RX_DMA              |\
ISR_CMB_RX              |\
ISR_MAC_RX              )

// Interrupt Status Register
#define REG_RFD_RRD_IDX             0x1800
#define REG_TPD_IDX                 0x1804

/***************************** MII definition ***************************************/
/* PHY Common Register */
#define MII_BMCR                        0x00       
#define MII_BMSR                        0x01      
#define MII_PHYSID1                     0x02     
#define MII_PHYSID2                     0x03    
#define MII_ADVERTISE                   0x04    
#define MII_LPA                         0x05   
#define MII_EXPANSION                   0x06        
#define MII_AT001_CR                    0x09       
#define MII_AT001_SR                    0x0A        
#define MII_AT001_ESR                   0x0F        
#define MII_AT001_PSCR                  0x10        
#define MII_AT001_PSSR                  0x11       
#define MII_DCOUNTER                    0x12        
#define MII_FCSCOUNTER                  0x13       
#define MII_NWAYTEST                    0x14   
#define MII_RERRCOUNTER                 0x15        
#define MII_SREVISION                   0x16        
#define MII_RESV1                       0x17        
#define MII_LBRERROR                    0x18       
#define MII_PHYADDR                     0x19        
#define MII_RESV2                       0x1a        
#define MII_TPISTATUS                   0x1b       
#define MII_NCONFIG                     0x1c   
#define MII_DBG_ADDR                    0x1D
#define MII_DBG_DATA                    0x1E
#define MII_CDTC                        0x16
#define MII_CDTS	                0x1c   

// CDT 
#define CDTC_EN				1
#define CDTS_NORMAL			0 
#define CDTS_SHORT			1
#define CDTS_OPEN			2
#define CDTS_INVALID		3
#define CDTC_PAIR_OFFSET	8
#define CDTS_STATUS_OFFSET	8
#define CDTS_RESULT_OFFSET	0



/* PHY Control Register */
#define MII_CR_SPEED_SELECT_MSB                  0x0040  /* bits 6,13: 10=1000, 01=100, 00=10 */
#define MII_CR_COLL_TEST_ENABLE                  0x0080  /* Collision test enable */
#define MII_CR_FULL_DUPLEX                       0x0100  /* FDX =1, half duplex =0 */
#define MII_CR_RESTART_AUTO_NEG                  0x0200  /* Restart auto negotiation */
#define MII_CR_ISOLATE                           0x0400  /* Isolate PHY from MII */
#define MII_CR_POWER_DOWN                        0x0800  /* Power down */
#define MII_CR_AUTO_NEG_EN                       0x1000  /* Auto Neg Enable */
#define MII_CR_SPEED_SELECT_LSB                  0x2000  /* bits 6,13: 10=1000, 01=100, 00=10 */
#define MII_CR_LOOPBACK                          0x4000  /* 0 = normal, 1 = loopback */
#define MII_CR_RESET                             0x8000  /* 0 = normal, 1 = PHY reset */
#define MII_CR_SPEED_MASK                        0x2040
#define MII_CR_SPEED_1000                        0x0040
#define MII_CR_SPEED_100                         0x2000
#define MII_CR_SPEED_10                          0x0000


/* PHY Status Register */
#define MII_SR_EXTENDED_CAPS                     0x0001  /* Extended register capabilities */
#define MII_SR_JABBER_DETECT                     0x0002  /* Jabber Detected */
#define MII_SR_LINK_STATUS                       0x0004  /* Link Status 1 = link */
#define MII_SR_AUTONEG_CAPS                      0x0008  /* Auto Neg Capable */
#define MII_SR_REMOTE_FAULT                      0x0010  /* Remote Fault Detect */
#define MII_SR_AUTONEG_COMPLETE                  0x0020  /* Auto Neg Complete */
#define MII_SR_PREAMBLE_SUPPRESS                 0x0040  /* Preamble may be suppressed */
#define MII_SR_EXTENDED_STATUS                   0x0100  /* Ext. status info in Reg 0x0F */
#define MII_SR_100T2_HD_CAPS                     0x0200  /* 100T2 Half Duplex Capable */
#define MII_SR_100T2_FD_CAPS                     0x0400  /* 100T2 Full Duplex Capable */
#define MII_SR_10T_HD_CAPS                       0x0800  /* 10T   Half Duplex Capable */
#define MII_SR_10T_FD_CAPS                       0x1000  /* 10T   Full Duplex Capable */
#define MII_SR_100X_HD_CAPS                      0x2000  /* 100X  Half Duplex Capable */
#define MII_SR_100X_FD_CAPS                      0x4000  /* 100X  Full Duplex Capable */
#define MII_SR_100T4_CAPS                        0x8000  /* 100T4 Capable */

/* Link partner ability register. */
#define MII_LPA_SLCT                             0x001f  /* Same as advertise selector  */
#define MII_LPA_10HALF                           0x0020  /* Can do 10mbps half-duplex   */
#define MII_LPA_10FULL                           0x0040  /* Can do 10mbps full-duplex   */
#define MII_LPA_100HALF                          0x0080  /* Can do 100mbps half-duplex  */
#define MII_LPA_100FULL                          0x0100  /* Can do 100mbps full-duplex  */
#define MII_LPA_100BASE4                         0x0200  /* 100BASE-T4  */
#define MII_LPA_PAUSE                            0x0400  /* PAUSE */
#define MII_LPA_ASYPAUSE                         0x0800  /* Asymmetrical PAUSE */
#define MII_LPA_RFAULT                           0x2000  /* Link partner faulted        */
#define MII_LPA_LPACK                            0x4000  /* Link partner acked us       */
#define MII_LPA_NPAGE                            0x8000  /* Next page bit               */

/* Autoneg Advertisement Register */
#define MII_AR_SELECTOR_FIELD                   0x0001  /* indicates IEEE 802.3 CSMA/CD */
#define MII_AR_10T_HD_CAPS                      0x0020  /* 10T   Half Duplex Capable */
#define MII_AR_10T_FD_CAPS                      0x0040  /* 10T   Full Duplex Capable */
#define MII_AR_100TX_HD_CAPS                    0x0080  /* 100TX Half Duplex Capable */
#define MII_AR_100TX_FD_CAPS                    0x0100  /* 100TX Full Duplex Capable */
#define MII_AR_100T4_CAPS                       0x0200  /* 100T4 Capable */
#define MII_AR_PAUSE                            0x0400  /* Pause operation desired */
#define MII_AR_ASM_DIR                          0x0800  /* Asymmetric Pause Direction bit */
#define MII_AR_REMOTE_FAULT                     0x2000  /* Remote Fault detected */
#define MII_AR_NEXT_PAGE                        0x8000  /* Next Page ability supported */
#define MII_AR_SPEED_MASK                       0x01E0
#define MII_AR_DEFAULT_CAP_MASK                 0x0DE0

/* 1000BASE-T Control Register */
#define MII_AT001_CR_1000T_HD_CAPS              0x0100  /* Advertise 1000T HD capability */
#define MII_AT001_CR_1000T_FD_CAPS              0x0200  /* Advertise 1000T FD capability  */
#define MII_AT001_CR_1000T_REPEATER_DTE         0x0400  /* 1=Repeater/switch device port */
/* 0=DTE device */
#define MII_AT001_CR_1000T_MS_VALUE             0x0800  /* 1=Configure PHY as Master */
/* 0=Configure PHY as Slave */
#define MII_AT001_CR_1000T_MS_ENABLE            0x1000  /* 1=Master/Slave manual config value */
/* 0=Automatic Master/Slave config */
#define MII_AT001_CR_1000T_TEST_MODE_NORMAL     0x0000  /* Normal Operation */
#define MII_AT001_CR_1000T_TEST_MODE_1          0x2000  /* Transmit Waveform test */
#define MII_AT001_CR_1000T_TEST_MODE_2          0x4000  /* Master Transmit Jitter test */
#define MII_AT001_CR_1000T_TEST_MODE_3          0x6000  /* Slave Transmit Jitter test */
#define MII_AT001_CR_1000T_TEST_MODE_4          0x8000  /* Transmitter Distortion test */
#define MII_AT001_CR_1000T_SPEED_MASK           0x0300
#define MII_AT001_CR_1000T_DEFAULT_CAP_MASK     0x0300

/* 1000BASE-T Status Register */
#define MII_AT001_SR_1000T_LP_HD_CAPS           0x0400  /* LP is 1000T HD capable */
#define MII_AT001_SR_1000T_LP_FD_CAPS           0x0800  /* LP is 1000T FD capable */
#define MII_AT001_SR_1000T_REMOTE_RX_STATUS     0x1000  /* Remote receiver OK */
#define MII_AT001_SR_1000T_LOCAL_RX_STATUS      0x2000  /* Local receiver OK */
#define MII_AT001_SR_1000T_MS_CONFIG_RES        0x4000  /* 1=Local TX is Master, 0=Slave */
#define MII_AT001_SR_1000T_MS_CONFIG_FAULT      0x8000  /* Master/Slave config fault */
#define MII_AT001_SR_1000T_REMOTE_RX_STATUS_SHIFT   12
#define MII_AT001_SR_1000T_LOCAL_RX_STATUS_SHIFT    13

/* Extended Status Register */
#define MII_AT001_ESR_1000T_HD_CAPS             0x1000  /* 1000T HD capable */
#define MII_AT001_ESR_1000T_FD_CAPS             0x2000  /* 1000T FD capable */
#define MII_AT001_ESR_1000X_HD_CAPS             0x4000  /* 1000X HD capable */
#define MII_AT001_ESR_1000X_FD_CAPS             0x8000  /* 1000X FD capable */

/* AT001 PHY Specific Control Register */
#define MII_AT001_PSCR_JABBER_DISABLE           0x0001  /* 1=Jabber Function disabled */
#define MII_AT001_PSCR_POLARITY_REVERSAL        0x0002  /* 1=Polarity Reversal enabled */
#define MII_AT001_PSCR_SQE_TEST                 0x0004  /* 1=SQE Test enabled *//
#define MII_AT001_PSCR_MAC_POWERDOWN            0x0008 
#define MII_AT001_PSCR_CLK125_DISABLE           0x0010  /* 1=CLK125 low,
* 0=CLK125 toggling
*/
#define MII_AT001_PSCR_MDI_MANUAL_MODE          0x0000  /* MDI Crossover Mode bits 6:5 */
/* Manual MDI configuration */
#define MII_AT001_PSCR_MDIX_MANUAL_MODE         0x0020  /* Manual MDIX configuration */
#define MII_AT001_PSCR_AUTO_X_1000T             0x0040  /* 1000BASE-T: Auto crossover,
*  100BASE-TX/10BASE-T:
*  MDI Mode
*/
#define MII_AT001_PSCR_AUTO_X_MODE              0x0060  /* Auto crossover enabled
* all speeds.
*/
#define MII_AT001_PSCR_10BT_EXT_DIST_ENABLE     0x0080
/* 1=Enable Extended 10BASE-T distance
 * (Lower 10BASE-T RX Threshold)
 * 0=Normal 10BASE-T RX Threshold */
#define MII_AT001_PSCR_MII_5BIT_ENABLE          0x0100
/* 1=5-Bit interface in 100BASE-TX
 * 0=MII interface in 100BASE-TX */
#define MII_AT001_PSCR_SCRAMBLER_DISABLE        0x0200  /* 1=Scrambler disable */
#define MII_AT001_PSCR_FORCE_LINK_GOOD          0x0400  /* 1=Force link good */
#define MII_AT001_PSCR_ASSERT_CRS_ON_TX         0x0800  /* 1=Assert CRS on Transmit */
#define MII_AT001_PSCR_POLARITY_REVERSAL_SHIFT    1
#define MII_AT001_PSCR_AUTO_X_MODE_SHIFT          5
#define MII_AT001_PSCR_10BT_EXT_DIST_ENABLE_SHIFT 7


/* AT001 PHY Specific Status Register */
#define MII_AT001_PSSR_SPD_DPLX_RESOLVED        0x0800  /* 1=Speed & Duplex resolved */
#define MII_AT001_PSSR_DPLX                     0x2000  /* 1=Duplex 0=Half Duplex */
#define MII_AT001_PSSR_SPEED                    0xC000  /* Speed, bits 14:15 */
#define MII_AT001_PSSR_10MBS                    0x0000  /* 00=10Mbs */
#define MII_AT001_PSSR_100MBS                   0x4000  /* 01=100Mbs */
#define MII_AT001_PSSR_1000MBS                  0x8000  /* 10=1000Mbs */

/*********************PCI Command Register ******************************/
// PCI Command Register Bit Definitions
#define PCI_REG_COMMAND         0x04    // PCI Command Register
#define CMD_IO_SPACE            0x0001
#define CMD_MEMORY_SPACE        0x0002
#define CMD_BUS_MASTER          0x0004

/* Wake Up Filter Control */
#define AT_WUFC_LNKC 0x00000001 /* Link Status Change Wakeup Enable */
#define AT_WUFC_MAG  0x00000002 /* Magic Packet Wakeup Enable */
#define AT_WUFC_EX   0x00000004 /* Directed Exact Wakeup Enable */
#define AT_WUFC_MC   0x00000008 /* Multicast Wakeup Enable */
#define AT_WUFC_BC   0x00000010 /* Broadcast Wakeup Enable */

/************************************************************************************************************************/

/* Error Codes */

#define AT_SUCCESS                      0
#define AT_ERR_EEPROM                   1
#define AT_ERR_PHY                      2
#define AT_ERR_CONFIG                   3
#define AT_ERR_PARAM                    4
#define AT_ERR_MAC_TYPE                 5
#define AT_ERR_PHY_TYPE                 6
#define AT_ERR_PHY_SPEED                7
#define AT_ERR_PHY_RES                  8

#define SPEED_0             0xffff
#define SPEED_10            10
#define SPEED_100           100
#define SPEED_1000          1000
#define HALF_DUPLEX         1
#define FULL_DUPLEX         2

#define MEDIA_TYPE_AUTO_SENSOR          0
#define MEDIA_TYPE_1000M_FULL           1
#define MEDIA_TYPE_100M_FULL            2
#define MEDIA_TYPE_100M_HALF            3
#define MEDIA_TYPE_10M_FULL             4
#define MEDIA_TYPE_10M_HALF             5

#define ADVERTISE_10_HALF               0x0001
#define ADVERTISE_10_FULL               0x0002
#define ADVERTISE_100_HALF              0x0004
#define ADVERTISE_100_FULL              0x0008
#define ADVERTISE_1000_HALF             0x0010
#define ADVERTISE_1000_FULL             0x0020
#define AUTONEG_ADVERTISE_SPEED_DEFAULT 0x002F /* Everything but 1000-Half */
#define AUTONEG_ADVERTISE_10_100_ALL    0x000F /* All 10/100 speeds*/
#define AUTONEG_ADVERTISE_10_ALL        0x0003 /* 10Mbps Full & Half speeds*/


/* The size (in bytes) of a ethernet packet */
#define ENET_HEADER_SIZE                14
#define MAXIMUM_ETHERNET_FRAME_SIZE     1518 /* with FCS */
#define MINIMUM_ETHERNET_FRAME_SIZE     64   /* with FCS */
#define ETHERNET_FCS_SIZE               4
#define MAX_JUMBO_FRAME_SIZE            0x2800
#define VLAN_SIZE                       4

#define PHY_AUTO_NEG_TIME               45          /* 4.5 Seconds */
#define PHY_FORCE_TIME                  20          /* 2.0 Seconds */

/* For checksumming , the sum of all words in the EEPROM should equal 0xBABA */
#define EEPROM_SUM                      0xBABA
#define NODE_ADDRESS_SIZE               6


/* Statistics counters collected by the MAC */ 
typedef struct stats_msg_block {                                   
	// rx                                               
	uint32_t            rx_ok;                  // The number of good packet received.
	uint32_t            rx_bcast;               // The number of good broadcast packet received.
	uint32_t            rx_mcast;               // The number of good multicast packet received.
	uint32_t            rx_pause;               // The number of Pause packet received.
	uint32_t            rx_ctrl;                // The number of Control packet received other than Pause frame.
	uint32_t            rx_fcs_err;             // The number of packets with bad FCS.
	uint32_t            rx_len_err;             // The number of packets with mismatch of length field and actual size.
	uint32_t            rx_byte_cnt;            // The number of bytes of good packet received. FCS is NOT included.
	uint32_t            rx_runt;                // The number of packets received that are less than 64 byte long and with good FCS.
	uint32_t            rx_frag;                // The number of packets received that are less than 64 byte long and with bad FCS.
	uint32_t            rx_sz_64;               // The number of good and bad packets received that are 64 byte long.
	uint32_t            rx_sz_65_127;           // The number of good and bad packets received that are between 65 and 127-byte long.
	uint32_t            rx_sz_128_255;          // The number of good and bad packets received that are between 128 and 255-byte long.
	uint32_t            rx_sz_256_511;          // The number of good and bad packets received that are between 256 and 511-byte long.
	uint32_t            rx_sz_512_1023;         // The number of good and bad packets received that are between 512 and 1023-byte long.
	uint32_t            rx_sz_1024_1518;        // The number of good and bad packets received that are between 1024 and 1518-byte long.
	uint32_t            rx_sz_1519_max;         // The number of good and bad packets received that are between 1519-byte and MTU.
	uint32_t            rx_sz_ov;               // The number of good and bad packets received that are more than MTU size šC truncated by Selene.
	uint32_t            rx_rxf_ov;              // The number of frame dropped due to occurrence of RX FIFO overflow.
	uint32_t            rx_rrd_ov;              // The number of frame dropped due to occurrence of RRD overflow.
	uint32_t            rx_align_err;           // Alignment Error
	uint32_t            rx_bcast_byte_cnt;      // The byte count of broadcast packet received, excluding FCS.
	uint32_t            rx_mcast_byte_cnt;      // The byte count of multicast packet received, excluding FCS.
	uint32_t            rx_err_addr;            // The number of packets dropped due to address filtering.
	
	// tx                                   
	uint32_t            tx_ok;                  // The number of good packet transmitted.
	uint32_t            tx_bcast;               // The number of good broadcast packet transmitted.
	uint32_t            tx_mcast;               // The number of good multicast packet transmitted.
	uint32_t            tx_pause;               // The number of Pause packet transmitted.
	uint32_t            tx_exc_defer;           // The number of packets transmitted with excessive deferral.
	uint32_t            tx_ctrl;                // The number of packets transmitted is a control frame, excluding Pause frame.
	uint32_t            tx_defer;               // The number of packets transmitted that is deferred.
	uint32_t            tx_byte_cnt;            // The number of bytes of data transmitted. FCS is NOT included.
	uint32_t            tx_sz_64;               // The number of good and bad packets transmitted that are 64 byte long.
	uint32_t            tx_sz_65_127;           // The number of good and bad packets transmitted that are between 65 and 127-byte long.
	uint32_t            tx_sz_128_255;          // The number of good and bad packets transmitted that are between 128 and 255-byte long.
	uint32_t            tx_sz_256_511;          // The number of good and bad packets transmitted that are between 256 and 511-byte long.
	uint32_t            tx_sz_512_1023;         // The number of good and bad packets transmitted that are between 512 and 1023-byte long.
	uint32_t            tx_sz_1024_1518;        // The number of good and bad packets transmitted that are between 1024 and 1518-byte long.
	uint32_t            tx_sz_1519_max;         // The number of good and bad packets transmitted that are between 1519-byte and MTU.
	uint32_t            tx_1_col;               // The number of packets subsequently transmitted successfully with a single prior collision.
	uint32_t            tx_2_col;               // The number of packets subsequently transmitted successfully with multiple prior collisions.
	uint32_t            tx_late_col;            // The number of packets transmitted with late collisions.
	uint32_t            tx_abort_col;           // The number of transmit packets aborted due to excessive collisions.
	uint32_t            tx_underrun;            // The number of transmit packets aborted due to transmit FIFO underrun, or TRD FIFO underrun
	uint32_t            tx_rd_eop;              // The number of times that read beyond the EOP into the next frame area when TRD was not written timely
	uint32_t            tx_len_err;             // The number of transmit packets with length field does NOT match the actual frame size.
	uint32_t            tx_trunc;               // The number of transmit packets truncated due to size exceeding MTU.
	uint32_t            tx_bcast_byte;          // The byte count of broadcast packet transmitted, excluding FCS.
	uint32_t            tx_mcast_byte;          // The byte count of multicast packet transmitted, excluding FCS.
	uint32_t            smb_updated;            // 1: SMB Updated. This is used by software as the indication of the statistics update. 
	// Software should clear this bit as soon as retrieving the statistics information.
} _AT_ATTRIB_PACK_ stats_msg_block_t;  

/* Coalescing Message Block */ 
typedef struct coals_msg_block {                 
	uint32_t            int_stats;              // interrupt status
	uint16_t            rrd_prod_idx;           // TRD Producer Index.
	uint16_t            rfd_cons_idx;           // RFD Consumer Index.
	uint16_t            update;                 // Selene sets this bit every time it DMA the CMB to host memory. 
	// Software supposes to clear this bit when CMB information is processed.
	uint16_t            tpd_cons_idx;           // TPD Consumer Index.
} _AT_ATTRIB_PACK_  coals_msg_block_t;                                


/* RRD descriptor */                            
typedef struct rx_return_desc {                         
	uint8_t             num_buf;                // Number of RFD buffers used by the received packet
	uint8_t             resved;
	uint16_t            buf_indx;               // RFD Index of the first buffer
    union {
        uint32_t    valid;
        struct {
			uint16_t    rx_chksum;
            uint16_t    pkt_size;         
        } xsum_sz;
    }           xsz;
	
	uint16_t    pkt_flg;                // Packet flags
	uint16_t    err_flg;                // Error flags
	uint16_t            resved2;
	uint16_t            vlan_tag;               // VLAN TAG
} _AT_ATTRIB_PACK_ rx_return_desc_t ;  

#define PACKET_FLAG_ETH_TYPE        0x0080
#define PACKET_FLAG_VLAN_INS        0x0100
#define PACKET_FLAG_ERR             0x0200
#define PACKET_FLAG_IPV4            0x0400
#define PACKET_FLAG_UDP             0x0800
#define PACKET_FLAG_TCP             0x1000
#define PACKET_FLAG_BCAST           0x2000
#define PACKET_FLAG_MCAST           0x4000
#define PACKET_FLAG_PAUSE           0x8000



#define ERR_FLAG_CRC                0x0001
#define ERR_FLAG_CODE               0x0002
#define ERR_FLAG_DRIBBLE            0x0004   
#define ERR_FLAG_RUNT               0x0008
#define ERR_FLAG_OV                 0x0010
#define ERR_FLAG_TRUNC              0x0020
#define ERR_FLAG_IP_CHKSUM          0x0040
#define ERR_FLAG_L4_CHKSUM          0x0080
#define ERR_FLAG_LEN                0x0100
#define ERR_FLAG_DES_ADDR           0x0200                          

/* RFD descriptor */                            
typedef struct rx_free_desc {                           
	u64  buffer_addr;      // Address of the descriptor's data buffer
	u16  buf_len;          // Size of the receive buffer in host memory, in byte
	u16  coalese;     
} _AT_ATTRIB_PACK_ rx_free_desc_t;  


/* TPD definition */
typedef struct _TpdDescr {
    u64             addr;
    u16             buf_len :14;
    u16             dma_int :1;
    u16             tx_int  :1;
    u16             vlan;
    u16             eop     :1;
    u16             ipver   :1;     // 0 : IPV4, 1:IPV6
    u16             ins_vlan:1;
    u16             my_xsum :1;
    u16             segment :1;
    u16             ipxsum  :1;
    u16             tcpxsum :1;
    u16             udpxsum :1;
    u16             vlan_tag:1;
    u16             eth_type:1;
    u16             iphdrlen:4;
    u16             tcphdrlen:4;
    u16             hdr_flag:1;
    u16             tcp_mss :13;
} _AT_ATTRIB_PACK_  TpdDescr;
// Tpd for custom checksum 
typedef struct _TpdCXsumDescr {
    u64             addr;
    u16             buf_len :14;
    u16             dma_int :1;
    u16             tx_int  :1;
    u16             vlan;
    u16             eop     :1;
    u16             coals   :1;
    u16             ins_vlan:1;
    u16             my_xsum :1;
    u16             segment :1;
    u16             ipxsum  :1;
    u16             tcpxsum :1;
    u16             udpxsum :1;
    u16             vlan_tag:1;
    u16             eth_type:1;
    u16             iphdrlen:4;
    u16             tcphdrlen:2;
    u16             payld_ofs:8;
    u16             psdxsum_ofs:8;
} _AT_ATTRIB_PACK_ TpdCXsumDescr;

//#define MAX_TX_BUF_LEN  0x3000
#define AT_TX_BUF_LEN  2000
#define AT_RX_BUF_LEN  2000

/* DMA Order Settings */
typedef enum {
    at_dma_ord_in = 1,
    at_dma_ord_enh = 2,
    at_dma_ord_out = 4
} at_dma_order;

typedef enum {
    at_rcb_64 = 0,
    at_rcb_128 = 1
} at_dma_rcb;

typedef enum {
    at_dma_req_128 = 0,
    at_dma_req_256 = 1,
    at_dma_req_512 = 2,
    at_dma_req_1024 = 3,
    at_dma_req_2048 = 4,
    at_dma_req_4096 = 5
} at_dma_req_block;

typedef enum {
    at_10_half = 0,
    at_10_full = 1,
    at_100_half = 2,
    at_100_full = 3
} at_speed_duplex_type;



typedef struct _spi_flash_dev {
    const char*     manu_name;  // manufacturer id
    // op-code
    uint8_t    cmdWRSR;
    uint8_t    cmdREAD;
    uint8_t    cmdPROGRAM;
    uint8_t    cmdWREN;
    uint8_t    cmdWRDI;
    uint8_t    cmdRDSR;
    uint8_t    cmdRDID;
    uint8_t    cmdSECTOR_ERASE;
    uint8_t    cmdCHIP_ERASE;
} spi_flash_dev;


/* Structure containing variables used by the shared code (e1000_hw.c) */
struct at_hw {
    char *mmr_base;             //
    at_adapter *back;           //
	
    at_dma_order dma_ord;
    at_dma_rcb rcb_value;
    at_dma_req_block dmar_block;
    at_dma_req_block dmaw_block;
	
    uint8_t preamble_len;
    uint8_t max_retry;          // Retransmission maximum , afterwards the packet will be discarded.
    uint8_t jam_ipg;            // IPG to start JAM for collision based flow control in half-duplex mode. In unit of 8-bit time.
    uint8_t ipgt;               // Desired back to back inter-packet gap. The default is 96-bit time.
    uint8_t min_ifg;            // Minimum number of IFG to enforce in between RX frames. Frame gap below such IFP is dropped.
    uint8_t ipgr1;              // 64bit Carrier-Sense window
    uint8_t ipgr2;              // 96-bit IPG window
	
    uint8_t tpd_burst;          // Number of TPD to prefetch in a cache-aligned burst. Each TPD is 16-byte in length.
    uint8_t rfd_burst;          // Number of RFD to prefetch in a cache-aligned burst. Each RFD is 12-byte in length.
    uint8_t rfd_fetch_gap;      // 
    uint8_t rrd_burst;          // Threshold of number of RRDs can be retired in a burst. Each RRD is 16-byte in length.
    uint8_t tpd_fetch_th;       //
    uint8_t tpd_fetch_gap;
    uint16_t tx_jumbo_task_th;
    uint16_t txf_burst;         // Number of data byte to read in a cache-aligned burst. Each SRAM entry is 8-byte in length.
    uint16_t rx_jumbo_th;       // Jumbo packet size for non-VLAN packet. VLAN packet should add 4-byte
    uint16_t rx_jumbo_lkah;
    uint16_t rrd_ret_timer;     // RRD retirement timer. Decrement by 1 after every 512ns passes.
    uint16_t lcol;              // Collision Window
	
    uint16_t cmb_tpd;
    uint16_t cmb_rrd;
    uint16_t cmb_rx_timer;     
    uint16_t cmb_tx_timer;      
    uint32_t smb_timer;
    uint16_t MediaType;
    uint16_t autoneg_advertised;
    uint16_t pci_cmd_word;
	
    uint16_t mii_autoneg_adv_reg;
    uint16_t mii_1000t_ctrl_reg;
    
    uint32_t max_frame_size;    //
    
    uint16_t dev_rev; 
    uint16_t device_id;         //
    uint16_t vendor_id;         //
    uint16_t subsystem_id;      //
    uint16_t subsystem_vendor_id;//
    uint8_t revision_id;        //
	
    
    // spi flash
    uint8_t flash_vendor;
    
    uint8_t mac_addr[NODE_ADDRESS_SIZE];//
    uint8_t perm_mac_addr[NODE_ADDRESS_SIZE];//
	
    boolean_t phy_configured;
    volatile unsigned long force_ps; // force GPHY to power saving mode
	
};

#endif//_ATHEROS_HW_H__
